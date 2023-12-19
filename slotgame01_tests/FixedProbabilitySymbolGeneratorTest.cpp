#include "../slotgame01/RandomNumberGenerator.h"
#include "../slotgame01/FixedProbabilitySymbolGenerator.h"

#include <gmock/gmock.h>

class RandomNumberGeneratorMock : public RandomNumberGenerator
{
public:
    MOCK_METHOD(int, Generate, (), (override));
};

using namespace ::testing;

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

TEST(FixedProbabilitySymbolGeneratorTest, SomeTest)
{
    std::unique_ptr<RandomNumberGeneratorMock> rng_mock{ std::make_unique<RandomNumberGeneratorMock>() };

    EXPECT_CALL(*rng_mock, Generate())
        .WillOnce(Return(990))   // 4
        .WillOnce(Return(510))   // 2
        .WillOnce(Return(290))   // 0
        .WillOnce(Return(880))   // 3
        ;

    FixedProbabilitySymbolGeneratorTestable generator{
        { 
            300, //  1 -  30
            100, // 31 -  40
            400, // 41 -  80
            100, // 81 -  90
            100  // 91 - 100
        },
        std::move(rng_mock)
    };

    EXPECT_EQ(4, generator.GenerateSymbol());
    EXPECT_EQ(2, generator.GenerateSymbol());
    EXPECT_EQ(0, generator.GenerateSymbol());
    EXPECT_EQ(3, generator.GenerateSymbol());
}
