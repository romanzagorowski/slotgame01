#pragma once

// Represents prize for hitting some number of a symbol (Crown) on the game board.

struct CountBasedPrize
{
    int symbol;
    int count;  // 3, 4, 5
    int amount;
};
