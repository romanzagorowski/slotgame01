#include "ParseArgs.h"

bool ParseGamesCountArg(int argc, char* argv[], int& games_count)
{
    return false;
}

bool ParseStartCreditArg(int argc, char* argv[], int& start_credit)
{
    return false;
}

bool ParseCreditOutFileArg(int argc, char* argv[], std::string& credit_out_file)
{
    return false;
}

bool ParseSymbolsArg(int argc, char* argv[], std::vector<int>& symbols)
{
    return false;
}

bool ParseArgs(int argc, char* argv[],
    int& games_count,
    int& start_credit,
    std::string& credit_out_file,
    std::vector<int>& symbols
)
{
    return true;
}
