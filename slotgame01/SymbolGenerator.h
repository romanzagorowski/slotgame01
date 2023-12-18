#pragma once

class SymbolGenerator
{
public:
    virtual int GenerateSymbol() = 0;

public:
    virtual ~SymbolGenerator() = default;
};
