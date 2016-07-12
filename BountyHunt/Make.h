//
// Constructs an object with the arguments passed into the constructor.
//
// Created by Tamas Karpati on 2016-07-12.
//

#pragma once

#include <type_traits>

namespace bounty
{

template <typename T, typename... Args>
constexpr decltype(auto) make(Args&&... args)
{
    return T{ std::forward<Args>(args)... };
}

}