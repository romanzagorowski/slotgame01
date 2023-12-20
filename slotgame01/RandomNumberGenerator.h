#pragma once

// A base class/interface for variety of random number generators.

class RandomNumberGenerator
{
public:
    virtual int Generate() = 0;

public:
    virtual ~RandomNumberGenerator() = default;
};
