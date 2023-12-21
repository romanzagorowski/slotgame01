#pragma once

#include <vector>
#include <cassert>

// Represents a game board with 'cols' columns (reels) and 'rows' rows.
// Returns a symbol at the sprcific cross of a column and a row or all symbols as a vector.

class GameBoard
{
public:
    GameBoard(int cols, int rows, const std::vector<int>& symbols) :
        cols{ cols },
        rows{ rows },
        symbols{ symbols }
    {
    }

public:
    int GetSymbolAt(int col, int row) const
    {
        assert(col < cols);
        assert(row < rows);

        return symbols[row * cols + col];
    }

    const std::vector<int>& GetSymbols() const
    {
        return symbols;
    }

private:
    const int cols;
    const int rows;

    const std::vector<int> symbols;
};
