#pragma once

#include "SymbolGenerator.h"
#include "StdRandomNumberGenerator.h"

// Generates symbols using a standard random number generator.

class RandomSymbolGenerator : public SymbolGenerator
{
public:
    explicit RandomSymbolGenerator(int nof_symbols) :
        rng{ 0, nof_symbols - 1 }
    {
    }

public:
    int GenerateSymbol() override
    {
        return rng.Generate();
    }

    StdRandomNumberGenerator rng;
};
