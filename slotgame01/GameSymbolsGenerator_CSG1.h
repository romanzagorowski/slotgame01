#pragma once

#include "GameSymbolsGenerator.h"
#include "ColumnSymbolsGenerator.h"

#include <vector>

class GameSymbolsGenerator_CSG1 : public GameSymbolsGenerator
{
public:
    GameSymbolsGenerator_CSG1(int cols, int rows, ColumnSymbolsGenerator& column_symbols_generator) :
        cols{ cols },
        rows{ rows },
        column_symbols_generator{ column_symbols_generator }
    {
    }

public:
    std::vector<int> GenerateSymbols() override
    {
        std::vector<int> symbols(this->rows * this->cols, -1);

        for(std::size_t c = 0; c < this->cols; ++c)
        {
            const std::vector<int> column_symbols = this->column_symbols_generator.GenerateSymbols();

            for(std::size_t r = 0; r < this->rows; ++r)
            {
                symbols[r * this->cols + c] = column_symbols[r];
            }
        }

        return symbols;
    }

private:
    const int cols;
    const int rows;

    ColumnSymbolsGenerator column_symbols_generator;
};
