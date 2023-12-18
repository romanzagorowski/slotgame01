#pragma once

#include "SymbolsGenerator.h"

#include <random>

class RandomSymbolsGenerator : SymbolsGenerator
{
    std::random_device rd;
    std::mt19937 rng{ rd() };
    std::uniform_int_distribution<std::mt19937::result_type> d{ 0, 7 };

public:
    RandomSymbolsGenerator(int cols, int rows) :
        cols{ cols },
        rows{ rows }
    {
    }

    std::vector<int> Generate() override
    {
        std::vector<int> symbols(this->rows * this->cols, -1);

        for(std::size_t c = 0; c < this->cols; ++c)
        {
            const std::vector<int> column_symbols = this->GenerateColumnSymbols();

            for(std::size_t r = 0; r < this->rows; ++r)
            {
                symbols[r * this->cols + c] = column_symbols[r];
            }
        }

        return symbols;
    }

private:
    std::vector<int> GenerateColumnSymbols()
    {
        std::vector<int> symbols;

        bool has_symbol_0 = false;

        for(int i = 0; i < this->rows; ++i)
        {
            int symbol = d(rng);

            while(symbol == 0 && has_symbol_0)
            {
                symbol = d(rng);
            }

            symbols.push_back(symbol);

            has_symbol_0 |= (0 == symbol);
        }

        return symbols;
    }

private:
    const int cols;
    const int rows;
};
