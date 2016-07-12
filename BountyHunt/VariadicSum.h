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
constexpr auto variadic_sum(T&& n, Args&&... args)
{
    return n + variadic_sum(std::forward<Args>(args)...);
}

template <typename T>
constexpr decltype(auto) variadic_sum(T&& n)
{
    return std::forward<T>(n);
}

}