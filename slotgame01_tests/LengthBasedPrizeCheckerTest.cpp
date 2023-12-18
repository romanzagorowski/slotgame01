#include "../slotgame01/LengthBasedPrizeChecker.h"
#include "../slotgame01/BetLines.h"
#include "../slotgame01/LengthBasedPrizes.h"

#include <algorithm>

#include <gtest/gtest.h>

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

TEST(LengthBasedPrizeCheckerTest, HandlesPrizesOnMultipleBetLines)
{
    GameBoard board{
        5, 3,
        {
            2, 2, 2, 2, 2,
            0, 0, 0, 0, 0,
            3, 3, 3, 3, 3,
        }
    };

    LengthBasedPrizeChecker checker{ length_based_prizes };

    auto payouts = checker.CheckBetLines(betlines, board);

    ASSERT_EQ(4, payouts.size());

    LengthBasedPayout expected_payout_1{ 2, 5, 1000,  2 };
    LengthBasedPayout expected_payout_2{ 3, 5, 1000,  3 };
    LengthBasedPayout expected_payout_3{ 2, 3,  100, 20 };
    LengthBasedPayout expected_payout_4{ 3, 3,  100, 19 };

    EXPECT_NE(std::find(std::begin(payouts), std::end(payouts), expected_payout_1), std::end(payouts));
    EXPECT_NE(std::find(std::begin(payouts), std::end(payouts), expected_payout_2), std::end(payouts));
    EXPECT_NE(std::find(std::begin(payouts), std::end(payouts), expected_payout_3), std::end(payouts));
    EXPECT_NE(std::find(std::begin(payouts), std::end(payouts), expected_payout_4), std::end(payouts));
}
