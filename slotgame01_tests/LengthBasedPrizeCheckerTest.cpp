#include "pch.h"

#include "../slotgame01/LengthBasedPrizeChecker.h"
#include "../slotgame01/BetLines.h"
#include "../slotgame01/LengthBasedPrizes.h"

using namespace ::testing;

TEST(LengthBasedPrizeCheckerTest, HandlesNoPrizeGameBoard)
{
    GameBoard board{
        5, 3,
        {
            0, 1, 2, 3, 4,
            5, 6, 7, 6, 5,
            4, 3, 2, 1, 0
        }
    };

    LengthBasedPrizeChecker checker{ length_based_prizes };

    for(const auto& betline : betlines)
    {
        EXPECT_FALSE(checker.CheckBetLine(betline, board));
    }
}

TEST(LengthBasedPrizeCheckerTest, HandlesOnePrizeGameBoard)
{
    GameBoard board{
        5, 3,
        {
            0, 0, 0, 0, 0,
            7, 7, 7, 7, 7,
            0, 0, 0, 0, 0
        }
    };

    LengthBasedPrizeChecker checker{ length_based_prizes };

    auto payout = checker.CheckBetLine(betlines[0], board);

    ASSERT_TRUE(payout);

    LengthBasedPayout expected_payout{ 7, 5, 25000, 1 };

    EXPECT_EQ(*payout, expected_payout);
}
