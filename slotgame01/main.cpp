#include "SlotGameSimulator.h"
#include "BetLines.h"
#include "CountBasedPrizes.h"
#include "LengthBasedPrizes.h"
#include "FixedProbabilitySymbolGenerator.h"
#include "ReelSymbolsGenerator.h"
#include "GameSymbolsGenerator_RSG5.h"
#include "GameSymbolsGenerator_Const.h"
#include "ParseArgs.h"
#include "SimulationData.h"
#include "SymbolProbabilities.h"

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

namespace
{
    constexpr int kGameReels = 5;
    constexpr int kGameRows = 3;
    constexpr int kBetAmount = 100;
}

// Forward declarations

void OutputBalanceHistory(const std::vector<int>& balance_history, const std::string& output_file);
void OutputSimulationReport(const SimulationData& data);
void RunOneGameSimulation(const std::vector<int>& game_symbols);
void RunMultipleGamesSimulation(int games_count, int start_credit, const std::string& credit_out_file);
void PrintUsage(const char* argv0);

int main(int argc, char* argv[])
{
    int games_count{ 0 };
    int start_credit{ 5000000 };
    std::string credit_out_file{};
    std::vector<int> symbols;

    ParseArgs(
        argc, argv,
        games_count,
        start_credit,
        credit_out_file,
        symbols
    );

    if(games_count == 0 && symbols.empty())
    {
        PrintUsage(argv[0]);

        return -1;
    }

    if(!symbols.empty())
    {
        RunOneGameSimulation(symbols);
    }
    else
    {
        RunMultipleGamesSimulation(games_count, start_credit, credit_out_file);
    }

    return 0;
}

static
void PrintUsage(const char* argv0)
{
    std::cout << "Usage: " << argv0 << " -gamesCount 100000 [-startCredit 5000000] [-creditOutFile plik.txt]" << std::endl;
    std::cout << "       " << argv0 << " -symbols 0,1,2,3,4,5,5,5,5,5,6,6,6,6,6" << std::endl;
}

static
void OutputBalanceHistory(const std::vector<int>& balance_history, const std::string& output_file)
{
    std::ofstream stream{ output_file };

    if(!stream)
    {
        std::cerr << "ERROR: Failed to open file '" << output_file << "' for writing." << std::endl;

        return;
    }

    for(const int balance : balance_history)
    {
        stream << balance << std::endl;
    }
}

static
void OutputSimulationReport(const SimulationData& data)
{

    const double hf = 100.0 * data.won_games / data.games_count;
    const int total_bet_amount = data.bet_amount * data.games_count;
    const double rtp = 100.0 * data.total_payout_amount / total_bet_amount;

    std::cout << std::setprecision(2) << std::fixed;

    std::cout << "all_games: " << data.games_count << std::endl;
    std::cout << "won_games: " << data.won_games << std::endl;
    std::cout << "hf: " << hf << std::endl;
    std::cout << "total_payout_amount: " << data.total_payout_amount << std::endl;
    std::cout << "total_bet_amount: " << total_bet_amount << std::endl;
    std::cout << "rtp: " << rtp << std::endl;
    std::cout << std::endl;

    //-- betline

    auto total_betline_hit_count = 0;

    for(const auto& [betline, hit_count] : data.betline_hits)
    {
        total_betline_hit_count += hit_count;
    }

    for(const auto& [betline, hit_count] : data.betline_hits)
    {
        const double hit_count_percent = 100.0 * hit_count / total_betline_hit_count;

        std::cout
            << "betline: " << std::setw(2) << betline
            << ", hit_count: " << hit_count
            << ", hit_count %: " << hit_count_percent
            << std::endl;
    }

    //--- symbol LENGTH hit count

    auto total_symbol_length_hit_count = 0;
    auto total_symbol_length_amount = 0;

    for(const auto& [key, value] : data.symbol_length_hits)
    {
        const auto& [hit_count, amount] = value;

        total_symbol_length_hit_count += hit_count;
        total_symbol_length_amount += amount;
    }

    std::cout << std::endl;

    for(const auto& [key, value] : data.symbol_length_hits)
    {
        const auto& [symbol, length] = key;
        const auto& [hit_count, amount] = value;

        const double hit_count_percent = 100.0 * hit_count / total_symbol_length_hit_count;
        const double amount_percent = 100.0 * amount / total_symbol_length_amount;
        const double total_amount_percent = 100.0 * amount / data.total_payout_amount;
        const int cost = 100 * hit_count;
        const int profit = amount - cost;

        std::cout
            << "symbol: " << symbol
            << ", length: " << length
            << ", hit_count: " << std::setw(9) << hit_count
            << ", hit_count %: " << std::setw(6) << hit_count_percent
            << ", amount: " << std::setw(9) << amount
            << ", amount %: " << std::setw(6) << amount_percent
            << ", total amount %: " << std::setw(6) << total_amount_percent
            << ", cost: " << std::setw(9) << cost
            << ", profit: " << std::setw(10) << profit
            << std::endl;
    }

    //--- symbol COUNT hits

    auto total_symbol_count_hit_count = 0;
    auto total_symbol_count_amount = 0;

    for(const auto& [key, value] : data.symbol_count_hits)
    {
        const auto& [hit_count, amount] = value;

        total_symbol_count_hit_count += hit_count;
        total_symbol_count_amount += amount;
    }

    std::cout << std::endl;

    for(const auto& [key, value] : data.symbol_count_hits)
    {
        const auto& [symbol, count] = key;
        const auto& [hit_count, amount] = value;

        const double hit_count_percent = 100.0 * hit_count / total_symbol_count_hit_count;
        const double amount_percent = 100.0 * amount / total_symbol_count_amount;
        const double total_amount_percent = 100.0 * amount / data.total_payout_amount;
        const int cost = data.bet_amount * hit_count;
        const int profit = amount - cost;

        std::cout
            << "symbol: " << symbol
            << ",  count: " << count
            << ", hit_count: " << std::setw(9) << hit_count
            << ", hit_count %: " << std::setw(6) << hit_count_percent
            << ", amount: " << std::setw(9) << amount
            << ", amount %: " << std::setw(6) << amount_percent
            << ", total amount %: " << std::setw(6) << total_amount_percent
            << ", cost: " << std::setw(9) << cost
            << ", profit: " << std::setw(10) << profit
            << std::endl;
    }
}

static
void RunOneGameSimulation(const std::vector<int>& game_symbols)
{
    SlotGameSimulator simulator{
        kGameReels, kGameRows,
        ___betlines,
        ___length_based_prizes,
        ___count_based_prizes
    };

    GameSymbolsGenerator_Const generator{ game_symbols };

    int payout = simulator.RunOneGame(
        generator
    );

    std::cout << payout << std::endl;
}

static
void RunMultipleGamesSimulation(
    int games_count,
    int start_credit,
    const std::string& credit_out_file
)
{
    // The game simulator with betlines and prizes defined.

    SlotGameSimulator simulator{
        kGameReels, kGameRows,
        ___betlines,
        ___length_based_prizes,
        ___count_based_prizes
    };

    // Symbol generators.
    // Each generator has its own symbol probability vector provided.

    FixedProbabilitySymbolGenerator sg1{ ___sp1 };
    FixedProbabilitySymbolGenerator sg2{ ___sp2 };
    FixedProbabilitySymbolGenerator sg3{ ___sp3 };
    FixedProbabilitySymbolGenerator sg4{ ___sp4 };
    FixedProbabilitySymbolGenerator sg5{ ___sp5 };

    // Symbol generator for each reel (3 symbols).

    ReelSymbolsGenerator rsg1{ kGameRows, sg1 };
    ReelSymbolsGenerator rsg2{ kGameRows, sg2 };
    ReelSymbolsGenerator rsg3{ kGameRows, sg3 };
    ReelSymbolsGenerator rsg4{ kGameRows, sg4 };
    ReelSymbolsGenerator rsg5{ kGameRows, sg5 };

    // Game symbol generator (15 symbols) with separate generator for each reel.

    GameSymbolsGenerator_RSG5 generator{
        kGameReels, kGameRows,
        { &rsg1, &rsg2, &rsg3, &rsg4, &rsg5 }
    };

    // Gathers simulation data/outcome.

    SimulationData simulation_data{
        ___betlines,
        ___length_based_prizes,
        ___count_based_prizes,
        games_count,
        start_credit,
        kBetAmount
    };

    simulator.RunMultipleGames(
        games_count,
        generator,
        simulation_data
    );

    OutputSimulationReport(simulation_data);

    if(!credit_out_file.empty())
    {
        OutputBalanceHistory(simulation_data.balance_history, credit_out_file);
    }
}
