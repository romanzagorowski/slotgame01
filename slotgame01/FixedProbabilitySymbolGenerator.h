#pragma once

#include "SymbolGenerator.h"
#include "RandomNumberGenerator.h"

#include <vector>
#include <numeric>
#include <memory>
#include <cassert>

class FixedProbabilitySymbolGenerator : public SymbolGenerator
{
public:
    FixedProbabilitySymbolGenerator(
        const std::vector<int>& symbol_probabilities
    ) :
        FixedProbabilitySymbolGenerator{ symbol_probabilities, std::make_unique<RandomNumberGenerator>(1, 100) }
    {
    }

protected:
    FixedProbabilitySymbolGenerator(
        const std::vector<int>& symbol_probabilities,
        std::unique_ptr<IRandomNumberGenerator> rng
    ) :
        symbol_probabilities{ symbol_probabilities },
        rng{ std::move(rng) }
    {
        assert(100 == std::accumulate(std::begin(symbol_probabilities), std::end(symbol_probabilities), 0));
    }

public:
    int GenerateSymbol() override
    {
        const int r = rng->Generate();

        int t = 100;

        for(int i = static_cast<int>(symbol_probabilities.size()) - 1; i >= 0; --i)
        {
            if(0 == symbol_probabilities[i])
                continue;

            t -= symbol_probabilities[i];

            if(r > t)
                return i;
        }

        assert(false);  // we shall never get here...

        return -1;
    }

private:
    const std::vector<int> symbol_probabilities;
    std::unique_ptr<IRandomNumberGenerator> rng;
};
