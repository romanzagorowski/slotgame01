#pragma once

class IRandomNumberGenerator
{
public:
    virtual int Generate() = 0;

public:
    virtual ~IRandomNumberGenerator() = default;
};
