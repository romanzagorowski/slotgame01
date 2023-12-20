#pragma once

#include <vector>
#include <cassert>

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
    int GetSymbolAt(std::size_t col, std::size_t row) const
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
