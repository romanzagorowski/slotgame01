#pragma once

#include "GameSymbolsGenerator.h"
#include "RandomSymbolGenerator.h"
#include "ReelSymbolsGenerator.h"

// The GameSymbolsGenerator that generates symbols using random symbol (number) generator.
// Not used in the project. Kept for ilustration purpose how the GameSymbolGenerator can be specialized.

class GameSymbolsGenerator_Random : public GameSymbolsGenerator
{
public:
    GameSymbolsGenerator_Random(int reels, int rows, int nof_symbols) :
        reels{ reels },
        rows{ rows },
        symbol_generator{ nof_symbols },
        reel_symbols_generator{ rows, symbol_generator }
    {
    }

public:
    std::vector<int> GenerateSymbols() override
    {
        std::vector<int> symbols(rows * reels, -1);

        for(std::size_t reel = 0; reel < reels; ++reel)
        {
            const std::vector<int> reel_symbols = reel_symbols_generator.GenerateSymbols();

            for(std::size_t row = 0; row < rows; ++row)
            {
                symbols[row * reels + reel] = reel_symbols[row];
            }
        }

        return symbols;
    }

private:
    const int reels;
    const int rows;

    RandomSymbolGenerator symbol_generator;
    ReelSymbolsGenerator reel_symbols_generator;
};
