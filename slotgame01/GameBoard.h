#pragma once

#include <vector>
#include <cassert>

class GameBoard
{
public:
    GameBoard(std::size_t cols, std::size_t rows, const std::vector<int>& symbols) :
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

private:
    const std::size_t cols;
    const std::size_t rows;

    std::vector<int> symbols;
};
