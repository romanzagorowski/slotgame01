#pragma once

#include <vector>
#include <string>

// TODO: Write unit tests for these ParseXXXArg functions!

bool ParseGamesCountArg(int argc, char* argv[], int& games_count);

bool ParseStartCreditArg(int argc, char* argv[], int& start_credit);

bool ParseCreditOutFileArg(int argc, char* argv[], std::string& credit_out_file);

bool ParseSymbolsArg(int argc, char* argv[], std::vector<int>& symbols);

bool ParseArgs(int argc, char* argv[],
    int& games_count,
    int& start_credit,
    std::string& credit_out_file,
    std::vector<int>& symbols
);
