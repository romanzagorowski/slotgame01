#include "../slotgame01/GameBoard.h"
#include "../slotgame01/CountBasedPrizeChecker.h"
#include "../slotgame01/CountBasedPrizes.h"

#include "algorithm"

#include <gtest/gtest.h>

TEST(CountBasedPrizeCheckerTest, FindsFiveCrownSymbols)
{
    GameBoard board{
        5, 3,
        {
            0, 1, 2, 0, 4,
            5, 6, 0, 6, 5,
            4, 0, 2, 1, 0
        }
    };

    CountBasedPrizeChecker checker{
        ___count_based_prizes
    };

    const auto payouts = checker.CheckGameBoard(board);

    ASSERT_EQ(1, payouts.size());

    CountBasedPayout expected_payout{ 0, 5, 5000 };

    EXPECT_NE(std::find(std::begin(payouts), std::end(payouts), expected_payout), std::end(payouts));
}

TEST(CountBasedPrizeCheckerTest, FindsFourCrownSymbols)
{
    GameBoard board{
        5, 3,
        {
            0, 1, 2, 3, 4,
            5, 6, 0, 6, 5,
            4, 0, 2, 1, 0
        }
    };

    CountBasedPrizeChecker checker{
        ___count_based_prizes
    };

    const auto payouts = checker.CheckGameBoard(board);

    ASSERT_EQ(1, payouts.size());

    CountBasedPayout expected_payout{ 0, 4, 1000 };

    EXPECT_NE(std::find(std::begin(payouts), std::end(payouts), expected_payout), std::end(payouts));
}

TEST(CountBasedPrizeCheckerTest, FindsThreeCrownSymbols)
{
    GameBoard board{
        5, 3,
        {
            0, 1, 2, 3, 4,
            5, 6, 0, 6, 5,
            4, 0, 2, 1, 4
        }
    };

    CountBasedPrizeChecker checker{
        ___count_based_prizes
    };

    const auto payouts = checker.CheckGameBoard(board);

    ASSERT_EQ(1, payouts.size());

    CountBasedPayout expected_payout{ 0, 3, 200 };

    EXPECT_NE(std::find(std::begin(payouts), std::end(payouts), expected_payout), std::end(payouts));
}

TEST(CountBasedPrizeCheckerTest, FindsZeroCrownSymbols)
{
    GameBoard board{
        5, 3,
        {
            7, 1, 2, 3, 4,
            5, 6, 0, 6, 5,
            4, 0, 2, 1, 4
        }
    };

    CountBasedPrizeChecker checker{
        ___count_based_prizes
    };

    const auto payouts = checker.CheckGameBoard(board);

    ASSERT_EQ(0, payouts.size());
}
