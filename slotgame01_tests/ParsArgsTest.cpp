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

    const int expected_games_count{ 100000 };
    const int expected_start_credit{ 5000000 };
    const std::string expected_credit_out_file{ "plik.txt" };
    const std::vector<int> expected_symbols{ 0,1,2,3,4,5,5,5,5,5,6,6,6,6,6 };

};

TEST_F(ParseArgsTest, ParsesGamesCountArg)
{
    int games_count{ 0 };

    ASSERT_TRUE(ParseGamesCountArg(argc, argv, games_count));
    EXPECT_EQ(expected_games_count, games_count);
}

TEST_F(ParseArgsTest, ParsesStartCreditArg)
{
    int start_credit{ 0 };

    ASSERT_TRUE(ParseStartCreditArg(argc, argv, start_credit));
    EXPECT_EQ(expected_start_credit, start_credit);
}

TEST_F(ParseArgsTest, ParsesCreditOutFileArg)
{
    std::string credit_out_file;

    ASSERT_TRUE(ParseCreditOutFileArg(argc, argv, credit_out_file));
    EXPECT_EQ(expected_credit_out_file, credit_out_file);
}

TEST_F(ParseArgsTest, ParsesSymbolsArg)
{
    const std::vector<int> expected_symbols{ 0,1,2,3,4,5,5,5,5,5,6,6,6,6,6 };

    std::vector<int> symbols;

    ASSERT_TRUE(ParseSymbolsArg(argc, argv, symbols));
    EXPECT_EQ(expected_symbols, symbols);
}

TEST_F(ParseArgsTest, ParsesArgs)
{
    int games_count{ 0 };
    int start_credit{ 0 };
    std::string credit_out_file;
    std::vector<int> symbols;

    ASSERT_TRUE(ParseArgs(argc, argv, games_count, start_credit, credit_out_file, symbols));
    EXPECT_EQ(expected_games_count, games_count);
    EXPECT_EQ(expected_start_credit, start_credit);
    EXPECT_EQ(expected_credit_out_file, credit_out_file);
    EXPECT_EQ(expected_symbols, symbols);
}

// TODO: Write negative tests here like: FailesToParseGamesCount, and so on.
