#pragma once

#include "GameSymbolsGenerator.h"

#include <vector>

// The GameSymbolsGenerator that constantly returns the same symbols.

class GameSymbolsGenerator_Const : public GameSymbolsGenerator
{
public:
    explicit GameSymbolsGenerator_Const(const std::vector<int>& symbols) :
        symbols{ symbols }
    {
    }

public:
    std::vector<int> GenerateSymbols() override
    {
        return symbols;
    }

private:
    std::vector<int> symbols;
};
