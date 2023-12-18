#pragma once

#include <vector>

class SymbolsGenerator
{
public:
    virtual std::vector<int> Generate() = 0;

public:
    virtual ~SymbolsGenerator() = default;
};
