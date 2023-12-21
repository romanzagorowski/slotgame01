#include "../slotgame01/BetLines.h"
#include "../slotgame01/GameBoard.h"

#include <gtest/gtest.h>

using namespace ::testing;

class BetLineTest : public Test
{
protected:
    const GameBoard game_board{
        5, 3,
        {
             0,  1,  2,  3,  4,
             5,  6,  7,  8,  9,
            10, 11, 12, 13, 14
        }
    };

    const std::vector<int> expected_betline_symbols[20]{
        {  5,  6,  7,  8,  9 }, //  1
        {  0,  1,  2,  3,  4 }, //  2
        { 10, 11, 12, 13, 14 }, //  3
        {  5,  6,  2,  8,  9 }, //  4
        {  0,  6, 12,  8,  4 }, //  5
        { 10,  6,  2,  8, 14 }, //  6
        {  5,  1,  7,  3,  9 }, //  7
        {  5, 11,  7, 13,  9 }, //  8
        {  0,  1,  7, 13, 14 }, //  9
        { 10, 11,  7,  3,  4 }, // 10
        { 10,  6,  2,  8,  9 }, // 11
        { 10,  6,  2,  3,  4 }, // 12
        {  0,  6, 12, 13, 14 }, // 13
        {  0,  6, 12,  8,  9 }, // 14
        {  0,  6,  2,  8,  4 }, // 15
        { 10,  6, 12,  8, 14 }, // 16
        {  0,  1,  7,  8,  9 }, // 17
        { 10, 11,  7,  8,  9 }, // 18
        { 10, 11, 12,  8,  4 }, // 19
        {  0,  1,  2,  8, 14 }, // 20
    };
};

// Tests if BetLine.GetSymbols() method returns appropriate symbols.

TEST_F(BetLineTest, GetSymbolsWorks) 
{
    for(std::size_t i = 0; i < std::size(___betlines); ++i)
    {
        const auto betline_symbols = ___betlines[i].GetSymbols(game_board);

        EXPECT_EQ(
            betline_symbols,
            expected_betline_symbols[i]
        );
    }
}
