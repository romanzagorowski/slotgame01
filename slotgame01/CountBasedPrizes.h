#pragma once

#include "CountBasedPrize.h"

#include <vector>

inline static const std::vector<CountBasedPrize> count_based_prizes{
    { 0, 5, 5000 },
    { 0, 4, 1000 },
    { 0, 3,  200 }, // crown
};
