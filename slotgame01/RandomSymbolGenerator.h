#pragma once

#include "SymbolGenerator.h"
#include "RandomNumberGenerator.h"

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

    RandomNumberGenerator rng;
};
