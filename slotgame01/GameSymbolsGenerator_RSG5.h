#pragma once

#include "GameSymbolsGenerator.h"
#include "ReelSymbolsGenerator.h"

// The game symbols generator with a separate reel symbols generator for each reel.

class GameSymbolsGenerator_RSG5 : public GameSymbolsGenerator
{
public:
    GameSymbolsGenerator_RSG5(int reels, int rows, const std::vector<ReelSymbolsGenerator*>& reel_symbols_generators) :
        reels{ reels },
        rows{ rows },
        reel_symbols_generators{ reel_symbols_generators }
    {
    }

public:
    std::vector<int> GenerateSymbols() override
    {
        std::vector<int> symbols(rows * reels, -1);

        for(std::size_t reel = 0; reel < reels; ++reel)
        {
            const std::vector<int> column_symbols = reel_symbols_generators[reel]->GenerateSymbols();

            for(std::size_t row = 0; row < rows; ++row)
            {
                symbols[row * reels + reel] = column_symbols[row];
            }
        }

        return symbols;
    }

public:
    const int reels;
    const int rows;

    std::vector<ReelSymbolsGenerator*> reel_symbols_generators;
};
