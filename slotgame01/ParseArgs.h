#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <string>

// Argument parsing routines.

inline bool ValidateSymbolsString(const std::string& s)
{
    // check size

    if(s.size() != 29)
    {
        return false;
    }

    // check symbols

    for(std::size_t i = 0; i < s.size(); i += 2)
    {
        if(!(s[i] >= '0' && s[i] <= '7'))
        {
            return false;
        }
    }

    // check separators

    for(std::size_t i = 1; i < s.size() - 1; i += 2)
    {
        if(s[i] != ',')
        {
            return false;
        }
    }

    return true;
}

inline int FindArg(int argc, char* argv[], const char* arg)
{
    for(int i = 0; i < argc; ++i)
    {
        if(std::strcmp(argv[i], arg) == 0)
        {
            return i;
        }
    }

    return -1;
}

inline bool ParseIntArg(int argc, char* argv[], const char* arg_name, int& arg_value)
{
    const int arg_index = FindArg(argc, argv, arg_name);

    if(arg_index == -1)
    {
        return false;
    }

    const int arg_value_index = arg_index + 1;

    if(!(arg_value_index < argc))
    {
        return false;
    }

    try 
    {
        arg_value = std::stoi(argv[arg_value_index]);
    }
    catch(...)
    {
        return false;
    }

    return true;
}

inline bool ParseStringArg(int argc, char* argv[], const char* arg_name, std::string& arg_value)
{
    if(const int arg_index = FindArg(argc, argv, arg_name); arg_index != -1)
    {
        const int arg_value_index = arg_index + 1;

        if(!(arg_value_index < argc))
        {
            return false;
        }

        arg_value = argv[arg_value_index];
    }

    return true;
}

inline bool ParseGamesCountArg(int argc, char* argv[], int& games_count)
{
    return ParseIntArg(argc, argv, "-gamesCount", games_count);
}

inline bool ParseStartCreditArg(int argc, char* argv[], int& start_credit)
{
    return ParseIntArg(argc, argv, "-startCredit", start_credit);
}

inline bool ParseCreditOutFileArg(int argc, char* argv[], std::string& credit_out_file)
{
    return ParseStringArg(argc, argv, "-creditOutFile", credit_out_file);
}

inline bool ParseSymbolsArg(int argc, char* argv[], std::vector<int>& symbols)
{
    std::string s;

    if(!ParseStringArg(argc, argv, "-symbols", s))
    {
        return false;
    }

    if(!ValidateSymbolsString(s))
    {
        return false;
    }

    for(int i = 0; i < s.size(); i += 2)
    {
        symbols.push_back(s[i] - '0');
    }

    return true;
}

inline bool ParseArgs(int argc, char* argv[],
    int& games_count,
    int& start_credit,
    std::string& credit_out_file,
    std::vector<int>& symbols
)
{
    return 
        ParseGamesCountArg(argc, argv, games_count) &&
        ParseStartCreditArg(argc, argv, start_credit) &&
        ParseCreditOutFileArg(argc, argv, credit_out_file) &&
        ParseSymbolsArg(argc, argv, symbols)
        ;
}
