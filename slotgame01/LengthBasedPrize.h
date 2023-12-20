#pragma once

// Represents a prize for a hitting a bet line.

struct LengthBasedPrize
{
    int symbol; // 1, 2, 3, 4, 5, 6, 7
    int length; // 2, 3, 4, 5
    int amount; // > 0
};
