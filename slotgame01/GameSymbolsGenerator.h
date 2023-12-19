#pragma once

#include <vector>

class GameSymbolsGenerator
{
public:
    virtual std::vector<int> GenerateSymbols() = 0;

public:
    virtual ~GameSymbolsGenerator() = default;
};
