#pragma once

#include <vector>
#include <string>

// TODO: Write unit tests for these ParseXXXArg functions!

// Argument parsing routines.

inline bool ParseGamesCountArg(int argc, char* argv[], int& games_count)
{
    return false;
}

inline bool ParseStartCreditArg(int argc, char* argv[], int& start_credit)
{
    return false;
}

inline bool ParseCreditOutFileArg(int argc, char* argv[], std::string& credit_out_file)
{
    return false;
}

inline bool ParseSymbolsArg(int argc, char* argv[], std::vector<int>& symbols)
{
    return false;
}

inline bool ParseArgs(int argc, char* argv[],
    int& games_count,
    int& start_credit,
    std::string& credit_out_file,
    std::vector<int>& symbols
)
{
    return true;
}
