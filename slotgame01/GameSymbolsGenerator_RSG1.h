#pragma once

#include "GameSymbolsGenerator.h"
#include "ReelSymbolsGenerator.h"

#include <vector>

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

        for(std::size_t c = 0; c < reels; ++c)
        {
            const std::vector<int> column_symbols = reel_symbols_generator.GenerateSymbols();

            for(std::size_t r = 0; r < rows; ++r)
            {
                symbols[r * reels + c] = column_symbols[r];
            }
        }

        return symbols;
    }

private:
    const int reels;
    const int rows;

    ReelSymbolsGenerator reel_symbols_generator;
};
