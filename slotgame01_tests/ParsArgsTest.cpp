#include "../slotgame01/ParseArgs.h"

#include <gtest/gtest.h>

class ParseArgsTest : public ::testing::Test
{
protected:
    char* argv[9]{
        "",
        "-gamesCount", "100000",
        "-startCredit", "5000000",
        "-creditOutFile", "plik.txt",
        "-symbols", "0,1,2,3,4,5,5,5,5,5,6,6,6,6,6"
    };
    int argc = static_cast<int>(std::size(argv));
};

TEST_F(ParseArgsTest, ParsesGamesCountArg)
{
    int games_count{ 0 };

    ASSERT_TRUE(ParseGamesCountArg(argc, argv, games_count));
    EXPECT_EQ(100000, games_count);
}

TEST_F(ParseArgsTest, ParsesStartCreditArg)
{
    int start_credit{ 0 };

    ASSERT_TRUE(ParseStartCreditArg(argc, argv, start_credit));
    EXPECT_EQ(5000000, start_credit);
}

TEST_F(ParseArgsTest, ParsesCreditOutFileArg)
{
    std::string credit_out_file;

    ASSERT_TRUE(ParseCreditOutFileArg(argc, argv, credit_out_file));
    EXPECT_EQ("plik.txt", credit_out_file);
}

TEST_F(ParseArgsTest, ParsesSymbolsArg)
{
    const std::vector<int> expected_symbols{ 0,1,2,3,4,5,5,5,5,5,6,6,6,6,6 };

    std::vector<int> symbols;

    ASSERT_TRUE(ParseSymbolsArg(argc, argv, symbols));
    EXPECT_EQ(expected_symbols, symbols);
}
