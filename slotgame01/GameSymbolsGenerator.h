#pragma once

#include <vector>

// Generates symbols for a game. 
// A base class for other, specialized game symbol generators.
// An interface for other components.

class GameSymbolsGenerator
{
public:
    virtual std::vector<int> GenerateSymbols() = 0;

public:
    virtual ~GameSymbolsGenerator() = default;
};
