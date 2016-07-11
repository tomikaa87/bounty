#pragma once

#include <cassert>
#include <memory>
#include <type_traits>

namespace bounty
{

template <class PtrType>
struct non_null
{
    template <typename = std::enable_if<std::is_pointer<PtrType>::value>::type>
    non_null(PtrType ptr)
        : m_ptr(ptr)
    {
        static_assert(std::is_pointer<PtrType>::value, "Template argument must be pointer type");
        assert(ptr);
    }

    template <class T, typename = std::enable_if<!std::is_pointer<PtrType>::value>::type>
    non_null(std::shared_ptr<T> ptr)
        : m_ptr(ptr)
    {
        assert(ptr);
    }

    non_null(nullptr_t) = delete;

    void operator=(nullptr_t) = delete;

    void operator=(const PtrType& o)
    {
        assert(o);
        m_ptr = o;
    }

    void operator=(PtrType&& o)
    {
        assert(o);
        m_ptr = std::move(o);
    }

    template <class T>
    void operator=(std::shared_ptr<T> o)
    {
        assert(o);
        m_ptr = o;
    }

    auto operator*() const
    {
        return *m_ptr;
    }

    auto operator->()
    {
        return m_ptr;
    }

private:
    PtrType m_ptr;
};

}