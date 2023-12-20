#pragma once

#include "GameSymbolsGenerator.h"
#include "ReelSymbolsGenerator.h"

#include <vector>

// The game symbol generator with one reel symbol generator for all reels.
// Not used in the project. Used to be...

class GameSymbolsGenerator_RSG1 : public GameSymbolsGenerator
{
public:
    GameSymbolsGenerator_RSG1(int reels, int rows, ReelSymbolsGenerator& reel_symbols_generator) :
        reels{ reels },
        rows{ rows },
        reel_symbols_generator{ reel_symbols_generator }
    {
    }

public:
    std::vector<int> GenerateSymbols() override
    {
        std::vector<int> symbols(rows * reels, -1);

        for(std::size_t reel = 0; reel < reels; ++reel)
        {
            const std::vector<int> column_symbols = reel_symbols_generator.GenerateSymbols();

            for(std::size_t row = 0; row < rows; ++row)
            {
                symbols[row * reels + reel] = column_symbols[row];
            }
        }

        return symbols;
    }

private:
    const int reels;
    const int rows;

    ReelSymbolsGenerator reel_symbols_generator;
};
