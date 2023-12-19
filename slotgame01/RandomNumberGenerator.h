#pragma once

class RandomNumberGenerator
{
public:
    virtual int Generate() = 0;

public:
    virtual ~RandomNumberGenerator() = default;
};
