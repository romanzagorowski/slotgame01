#include "../slotgame01/IRandomNumberGenerator.h"
#include "../slotgame01/FixedProbabilitySymbolGenerator.h"

#include <gmock/gmock.h>

class RandomNumberGeneratorMock : public IRandomNumberGenerator
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
        std::unique_ptr<IRandomNumberGenerator> rng
    ) :
        FixedProbabilitySymbolGenerator{ symbol_probabilities, std::move(rng) }
    {
    }
};

TEST(FixedProbabilitySymbolGeneratorTest, SomeTest)
{
    std::unique_ptr<RandomNumberGeneratorMock> rng_mock{ std::make_unique<RandomNumberGeneratorMock>() };

    EXPECT_CALL(*rng_mock, Generate())
        .WillOnce(Return(99))   // 4
        .WillOnce(Return(51))   // 2
        .WillOnce(Return(29))   // 0
        .WillOnce(Return(88))   // 3
        ;

    FixedProbabilitySymbolGeneratorTestable generator{
        { 
            30, //  1 -  30
            10, // 31 -  40
            40, // 41 -  80
            10, // 81 -  90
            10  // 91 - 100
        },
        std::move(rng_mock)
    };

    EXPECT_EQ(4, generator.GenerateSymbol());
    EXPECT_EQ(2, generator.GenerateSymbol());
    EXPECT_EQ(0, generator.GenerateSymbol());
    EXPECT_EQ(3, generator.GenerateSymbol());
}
