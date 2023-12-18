#pragma once

#include "SymbolsGenerator.h"

#include <random>
#include <array>
#include <utility>
#include <cassert>
#include <numeric>

class FixedProbabilitySymbolsGenerator : public SymbolsGenerator
{
public:
    FixedProbabilitySymbolsGenerator(int cols, int rows) :
        cols{ cols },
        rows{ rows }
    {
        assert(100 == std::accumulate(std::begin(symbol_probabilities), std::end(symbol_probabilities), 0));
    }

public:
    std::vector<int> Generate()
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

    std::array<int, 8> symbol_probabilities{
        12, // 0 - crown

        16, // 1 - cherries
        12, // 2 - lemon
        12, // 3 - orange
        12, // 4 - plum

        12, // 5 - grapes
        12, // 6 - watermelon
        12  // 7 - seven
    };

private:
    std::vector<int> GenerateColumnSymbols()
    {
        std::vector<int> symbols;

        bool has_symbol_0 = false;

        for(int i = 0; i < this->rows; ++i)
        {
            int symbol = this->GenerateSymbol();

            while(symbol == 0 && has_symbol_0)
            {
                symbol = this->GenerateSymbol();
            }

            symbols.push_back(symbol);

            has_symbol_0 |= (0 == symbol);
        }

        return symbols;
    }

    int GenerateSymbol()
    {
        const int r = d(rng);

        int t = 100;

        for(int i = 7; i >= 0; --i)
        {
            t -= symbol_probabilities[i];

            if(r > t)
                return i;
        }

        assert(false);  // we shall not get here...

        return 0;
    }

private:
    const int cols;
    const int rows;

    std::random_device rd;
    std::mt19937 rng{ rd() };
    std::uniform_int_distribution<std::mt19937::result_type> d{ 1, 100 };
};
