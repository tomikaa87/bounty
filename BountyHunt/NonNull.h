//
// Type wrapper that ensures the contained pointer won't be nullptr
//
// Created by Tamas Karpati on 2016-07-12.
//

#pragma once

#include <cassert>
#include <memory>
#include <type_traits>

namespace bounty
{

template <class T>
struct non_null
{
    constexpr explicit non_null(const T& ptr)
        : m_ptr(ptr)
    {
        static_assert(!std::is_null_pointer<T>::value, "Template argument must not be nullptr");
        assert(ptr != nullptr);
    }

    constexpr explicit non_null(const T&& ptr)
        : m_ptr(ptr)
    {
        static_assert(!std::is_null_pointer<T>::value, "Template argument must not be nullptr");
        assert(ptr != nullptr);
    }

    non_null(const nullptr_t&) = delete;
    non_null(int) = delete;

    non_null(const non_null&) = default;
    non_null(non_null&&) = default;

    non_null& operator=(const nullptr_t&) = delete;
    non_null& operator=(int) = delete;

    non_null& operator=(const T& o)
    {
        assert(o);
        m_ptr = o;
        return *this;
    }

    non_null& operator=(T&& o)
    {
        assert(o);
        m_ptr = std::move(o);
        return *this;
    }

    constexpr auto operator->() const
    {
        return m_ptr;
    }

    constexpr operator T() const
    {
        return m_ptr;
    }

    constexpr auto operator*() const
    {
        return *m_ptr;
    }

private:
    T m_ptr;
};

}