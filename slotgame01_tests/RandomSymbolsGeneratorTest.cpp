#include "pch.h"

#include "../slotgame01/RandomSymbolsGenerator.h"

#include <algorithm>
#include <cassert>

std::ostream& operator << (std::ostream& os, const std::vector<int>& v)
{
    assert(15 == v.size());

    for(std::size_t r = 0; r < 3; ++r)
    {
        for(std::size_t c = 0; c < 5; ++c)
        {
            os << v[r * 5 + c];
        }
        os << std::endl;
    }

    return os;
}

TEST(RandomSymbolsGeneratorTest, GeneratesSymbolsInRange)
{
    RandomSymbolsGenerator generator{ 5, 3 };

    for(int i = 0; i < 1000; ++i)
    {
        const std::vector<int> symbols = generator.Generate();

        const bool out_of_range = (std::find_if(
            std::begin(symbols), std::end(symbols),[](const auto& symbol) { return symbol < 0 || symbol > 7; }
        ) != std::end(symbols));

        ASSERT_FALSE(out_of_range) << symbols;
    }
}

TEST(RandomSymbolGeneratorTest, GeneratesMaxOneZeroPerColumn)
{
    RandomSymbolsGenerator generator{ 5, 3 };

    for(int i = 0; i < 1000; ++i)
    {
        const std::vector<int> symbols = generator.Generate();

        for(int col = 0; col < 5; ++col)
        {
            int zero_symbol_count = 0;

            for(int row = 0; row < 3; ++row)
            {
                if(symbols[row * 5 + col] == 0)
                {
                    zero_symbol_count++;
                }
            }

            ASSERT_TRUE(zero_symbol_count <= 1) << symbols;
        }
    }
}
