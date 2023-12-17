#pragma once

#include <vector>

class SymbolsGenerator
{
public:
    virtual std::vector<int> Generate() const = 0;

public:
    virtual ~SymbolsGenerator() = default;
};
