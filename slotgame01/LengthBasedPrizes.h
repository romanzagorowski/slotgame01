#pragma once

#include "LengthBasedPrize.h"

#include <vector>

// The length based prizes (fruits like) taken from the online game info screen.

inline static const std::vector<LengthBasedPrize> ___length_based_prizes{

    { 1, 5, 1000 },
    { 1, 4,  250 },
    { 1, 3,  100 },
    { 1, 2,   25 }, // cherries

    { 2, 5, 1000 },
    { 2, 4,  250 },
    { 2, 3,  100 }, // lemon

    { 3, 5, 1000 },
    { 3, 4,  250 },
    { 3, 3,  100 }, // orange

    { 4, 5, 1000 },
    { 4, 4,  250 },
    { 4, 3,  100 }, // plum

    { 5, 5, 2500 },
    { 5, 4, 1000 },
    { 5, 3,  250 }, // grapes

    { 6, 5, 2500 },
    { 6, 4, 1000 },
    { 6, 3,  250 }, // watermelon

    { 7, 5, 25000 },
    { 7, 4,  5000 },
    { 7, 3,   500 }, // seven
}
;
