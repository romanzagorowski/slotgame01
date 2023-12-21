#include "../slotgame01/LengthBasedPrizeChecker.h"
#include "../slotgame01/BetLines.h"
#include "../slotgame01/LengthBasedPrizes.h"

#include <algorithm>

#include <gtest/gtest.h>

using namespace ::testing;

// Shall find no prizes on a game board with no winning betlines.

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

    LengthBasedPrizeChecker checker{ ___length_based_prizes };
    auto payouts = checker.CheckBetLines(___betlines, board);

    EXPECT_TRUE(payouts.empty());
}

// On the game board with one winning betline
// shall find only one prize.

TEST(LengthBasedPrizeCheckerTest, HandlesOnePrizeGameBoard)
{
    GameBoard board{
        5, 3,
        {
            0, 0, 0, 0, 0,
            7, 7, 7, 7, 7,
            1, 2, 3, 4, 5
        }
    };

    LengthBasedPrizeChecker checker{ ___length_based_prizes };

    auto payouts = checker.CheckBetLines(___betlines, board);

    ASSERT_EQ(1, payouts.size());

    LengthBasedPayout expected_payout{ 7, 5, 25000, 1 };

    EXPECT_NE(std::find(std::begin(payouts), std::end(payouts), expected_payout), std::end(payouts));
}

// On the game board with multiple winning betlines
// shall find them all.

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

    LengthBasedPrizeChecker checker{ ___length_based_prizes };

    auto payouts = checker.CheckBetLines(___betlines, board);

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

// On the game board with winning betline of length 5
// shall find the 5 symbol lengh prize but not 4 or 3.

TEST(LengthBasedPrizeCheckerTest, FindsTheLongestWinningSequence)
{
    GameBoard board{
        5, 3,
        {
            0, 0, 0, 0, 0,
            7, 7, 7, 7, 7,
            1, 2, 3, 4, 5
        }
    };

    LengthBasedPrizeChecker checker{ ___length_based_prizes };

    auto payouts = checker.CheckBetLines(___betlines, board);

    LengthBasedPayout     expected_payout_5{ 7, 5, 25000, 1 };
    LengthBasedPayout not_expected_payout_4{ 7, 4,  5000, 1 };
    LengthBasedPayout not_expected_payout_3{ 7, 3,   500, 1 };

    ASSERT_NE(std::find(std::begin(payouts), std::end(payouts),     expected_payout_5), std::end(payouts));
    EXPECT_EQ(std::find(std::begin(payouts), std::end(payouts), not_expected_payout_4), std::end(payouts));
    EXPECT_EQ(std::find(std::begin(payouts), std::end(payouts), not_expected_payout_3), std::end(payouts));
}

static
std::vector<int> GenerateTestGameSymbols(int symbol, int n)
{
    std::vector<int> symbols{
        1, 2, 3, 4, 5,
        0, 0, 0, 0, 0,  // <- put n symbols here where n in (3, 4, 5)
        1, 2, 3, 4, 5,
    };

    for(int i = 0; i < n; ++i)
    {
        symbols[5 + i] = symbol;
    }

    return symbols;
}

// Tests all length based prizes.

TEST(LengthBasedPrizeCheckerTest, TestAllLengthBasedPrizes)
{
    LengthBasedPrizeChecker checker{ ___length_based_prizes };

    for(const auto& prize : ___length_based_prizes)
    {
        GameBoard board{
            5, 3, GenerateTestGameSymbols(prize.symbol, prize.length)
        };

        auto payouts = checker.CheckBetLines(___betlines, board);

        LengthBasedPayout expected_payout{ prize.symbol, prize.length, prize.amount, 1 };   // all tests on the betline 1

        ASSERT_NE(std::find(std::begin(payouts), std::end(payouts), expected_payout), std::end(payouts));
    }
}
