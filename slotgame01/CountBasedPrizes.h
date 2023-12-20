#pragma once

#include "CountBasedPrize.h"

#include <vector>

// Prize definitions for Crown symbol.
// Taken from the online game info screen.

inline static const std::vector<CountBasedPrize> ___count_based_prizes{
    { 0, 5, 5000 },
    { 0, 4, 1000 },
    { 0, 3,  200 }, // crown
};
