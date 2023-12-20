#pragma once

#include "RandomNumberGenerator.h"

#include <random>

// A random number generator that uses std library random number implementation.

class StdRandomNumberGenerator : public RandomNumberGenerator
{
public:
    StdRandomNumberGenerator(int min_value, int max_value) :
        uid{ min_value, max_value }
    {
    }

public:
    int Generate() override
    {
        return uid(rng);
    }

private:
    std::random_device rd;
    std::mt19937 rng{ rd() };
    std::uniform_int_distribution<int> uid;
};
