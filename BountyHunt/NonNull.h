#pragma once

#include <cassert>
#include <memory>
#include <type_traits>

namespace bounty
{

template <class PtrType>
struct non_null
{
    non_null(PtrType ptr)
        : m_ptr(ptr)
    {
        static_assert(std::is_assignable<PtrType, nullptr_t>::value, "Template argument must be a pointer type");
        static_assert(!std::is_null_pointer<PtrType>::value, "Template argument must not be nullptr");
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