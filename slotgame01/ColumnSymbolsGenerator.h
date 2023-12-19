#pragma once

#include "SymbolGenerator.h"

#include <vector>

class ColumnSymbolsGenerator
{
public:
    ColumnSymbolsGenerator(int width, SymbolGenerator& symbol_generator) :
        width{ width },
        symbol_generator{ symbol_generator }
    {

    }

    std::vector<int> GenerateSymbols()
    {
        std::vector<int> symbols;

        bool has_symbol_0 = false;

        for(int i = 0; i < this->width; ++i)
        {
            int symbol = symbol_generator.GenerateSymbol();

            while(symbol == 0 && has_symbol_0)
            {
                symbol = symbol_generator.GenerateSymbol();
            }

            symbols.push_back(symbol);

            has_symbol_0 |= (0 == symbol);
        }

        return symbols;
    }

private:
    const int width;
    SymbolGenerator& symbol_generator;
};
