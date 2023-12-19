#pragma once

#include "GameSymbolsGenerator.h"
#include "ColumnSymbolsGenerator.h"

class GameSymbolsGeneratorCSG5 : public GameSymbolsGenerator
{
public:
    GameSymbolsGeneratorCSG5(int cols, int rows, std::vector<ColumnSymbolsGenerator*> column_symbols_generators) :
        cols{ cols },
        rows{ rows },
        column_symbols_generators{ column_symbols_generators }
    {
    }

public:
    std::vector<int> GenerateSymbols() override
    {
        std::vector<int> symbols(this->rows * this->cols, -1);

        for(std::size_t c = 0; c < cols; ++c)
        {
            const std::vector<int> column_symbols = column_symbols_generators[c]->GenerateSymbols();

            for(std::size_t r = 0; r < this->rows; ++r)
            {
                symbols[r * cols + c] = column_symbols[r];
            }
        }

        return symbols;
    }

public:
    const int cols;
    const int rows;

    std::vector<ColumnSymbolsGenerator*> column_symbols_generators;
};
