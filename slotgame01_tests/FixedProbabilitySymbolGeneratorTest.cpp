#include "../slotgame01/RandomNumberGenerator.h"
#include "../slotgame01/FixedProbabilitySymbolGenerator.h"

#include <gmock/gmock.h>

class RandomNumberGeneratorMock : public RandomNumberGenerator
{
public:
    MOCK_METHOD(int, Generate, (), (override));
};

using namespace ::testing;

// Derive from testable class to have access to its protected constructor.

class FixedProbabilitySymbolGeneratorTestable : public FixedProbabilitySymbolGenerator
{
public:
    FixedProbabilitySymbolGeneratorTestable(
        const std::vector<int>& symbol_probabilities,
        std::unique_ptr<RandomNumberGenerator> rng
    ) :
        FixedProbabilitySymbolGenerator{ symbol_probabilities, std::move(rng) }
    {
    }
};

// Checks if for a series of sudo random numbers
// the symbol generator generates appropriate symbols.

TEST(FixedProbabilitySymbolGeneratorTest, CheckGeneratedSymbols)
{
    std::unique_ptr<RandomNumberGeneratorMock> rng_mock{ std::make_unique<RandomNumberGeneratorMock>() };

    EXPECT_CALL(*rng_mock, Generate())
        .WillOnce(Return(990))   // 99.0% -> 4
        .WillOnce(Return(515))   // 51.5% -> 2
        .WillOnce(Return(290))   // 29.0% -> 0
        .WillOnce(Return(880))   // 88.0% -> 3
        ;

    FixedProbabilitySymbolGeneratorTestable generator{
        { 
            300, //  1.0 -  30.0 -> 0
            100, // 31.0 -  40.0 -> 1
            400, // 41.0 -  80.0 -> 2
            100, // 81.0 -  90.0 -> 3
            100  // 91.0 - 100.0 -> 4
        },
        std::move(rng_mock)
    };

    EXPECT_EQ(4, generator.GenerateSymbol());
    EXPECT_EQ(2, generator.GenerateSymbol());
    EXPECT_EQ(0, generator.GenerateSymbol());
    EXPECT_EQ(3, generator.GenerateSymbol());
}
