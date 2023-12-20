#pragma once

// Generates one symbol at a time.
// A base class/interface for other symbol generators.

class SymbolGenerator
{
public:
    virtual int GenerateSymbol() = 0;

public:
    virtual ~SymbolGenerator() = default;
};
