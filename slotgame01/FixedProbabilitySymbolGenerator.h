#pragma once

#include "SymbolGenerator.h"
#include "StdRandomNumberGenerator.h"

#include <vector>
#include <numeric>
#include <memory>
#include <cassert>

// Generates symbols with probabilities define in the vector.
// Probabilities are define with accuracy to 1 decimal point as integers, so 100% is 1000.
// An index of probability in the vector is the symbol number (0 - crown, 1 - cherries, 2 - lemon and so on).

// For testing purpose, has a protected constructor that allows to provide an unique pointer to a random number generator (a mock for example).

class FixedProbabilitySymbolGenerator : public SymbolGenerator
{
public:
    FixedProbabilitySymbolGenerator(
        const std::vector<int>& symbol_probabilities
    ) :
        FixedProbabilitySymbolGenerator{ symbol_probabilities, std::make_unique<StdRandomNumberGenerator>(1, 1000) }
    {
    }

protected:
    FixedProbabilitySymbolGenerator(
        const std::vector<int>& symbol_probabilities,
        std::unique_ptr<RandomNumberGenerator> rng
    ) :
        symbol_probabilities{ symbol_probabilities },
        rng{ std::move(rng) }
    {
        assert(1000 == std::accumulate(std::begin(symbol_probabilities), std::end(symbol_probabilities), 0));
    }

public:
    int GenerateSymbol() override
    {
        const int r = rng->Generate();

        int t = 1000;

        for(int i = static_cast<int>(symbol_probabilities.size()) - 1; i >= 0; --i)
        {
            if(0 == symbol_probabilities[i])
                continue;

            t -= symbol_probabilities[i];

            if(r > t)
                return i;
        }

        assert(false);  // we shall never get here...

        return -1;  // some illegal symbol...
    }

private:
    const std::vector<int> symbol_probabilities;
    std::unique_ptr<RandomNumberGenerator> rng;
};
