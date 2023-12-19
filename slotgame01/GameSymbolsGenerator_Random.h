#pragma once

#include "GameSymbolsGenerator.h"
#include "RandomSymbolGenerator.h"
#include "ColumnSymbolsGenerator.h"

class GameSymbolsGenerator_Random : public GameSymbolsGenerator
{
public:
    GameSymbolsGenerator_Random(int cols, int rows, int nof_symbols) :
        cols{ cols },
        rows{ rows },
        symbol_generator{ nof_symbols },
        column_symbols_generator{ rows, symbol_generator }
    {
    }

public:
    std::vector<int> GenerateSymbols() override
    {
        std::vector<int> symbols(rows * cols, -1);

        for(std::size_t c = 0; c < cols; ++c)
        {
            const std::vector<int> column_symbols = column_symbols_generator.GenerateSymbols();

            for(std::size_t r = 0; r < rows; ++r)
            {
                symbols[r * cols + c] = column_symbols[r];
            }
        }

        return symbols;
    }

private:
    const int cols;
    const int rows;

    RandomSymbolGenerator symbol_generator;
    ColumnSymbolsGenerator column_symbols_generator;
};
