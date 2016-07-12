//
// A function that takes any number of parameters of any numeric type and returns the sum of it.
//
// Created by Tamas Karpati on 2016-07-12.
//

#pragma once

#include <type_traits>

namespace bounty
{

template <typename T, typename... Args>
constexpr auto variadic_sum(T n, Args... args)
{
    return n + variadic_sum(args...);
}

template <typename T>
constexpr auto variadic_sum(T n)
{
    static_assert(std::is_arithmetic<T>::value, "Only integral types can be used.");
    return n;
}

}