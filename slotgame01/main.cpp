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

#include "SymbolProbabilities07.h"
using namespace SymbolProbabilities07;

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

/*
inline std::ostream& operator << (std::ostream& os, const std::vector<int>& v)
{
    assert(15 == v.size());

    for(std::size_t r = 0; r < 3; ++r)
    {
        for(std::size_t c = 0; c < 5; ++c)
        {
            os << v[r * 5 + c];
        }
        os << std::endl;
    }

    return os;

    //os << "{ ";

    //std::string sep = "";

    //for(const auto& i : v)
    //{
    //    os << sep;

    //    if(sep == "")
    //        sep = ", ";

    //    os << i;
    //}

    //return os << " }";
}
*/

namespace
{
    constexpr int kGameReels = 5;
    constexpr int kGameRows = 3;
}

void OutputSimulationReport(const SimulationData& data)
{

    const double hf = 100.0 * data.won_games / data.games_count;
    const int bet_amount = 100 * data.games_count;
    const double rtp = 100.0 * data.total_payout_amount / bet_amount;

    std::cout << std::setprecision(2) << std::fixed;

    std::cout << "all_games: " << data.games_count << std::endl;
    std::cout << "won_games: " << data.won_games << std::endl;
    std::cout << "hf: " << hf << std::endl;
    std::cout << "total_payout_amount: " << data.total_payout_amount << std::endl;
    std::cout << "bet_amount: " << bet_amount << std::endl;
    std::cout << "rtp: " << rtp << std::endl;

    //-- betline

    auto total_betline_hit_count = 0;

    for(const auto& [betline, hit_count] : data.betline_hits)
    {
        total_betline_hit_count += hit_count;
    }

    for(const auto& [betline, hit_count] : data.betline_hits)
    {
        const double hit_count_percent = 100.0 * hit_count / total_betline_hit_count;

        std::cout << "betline: " << std::setw(2) << betline << ", hit_count: " << hit_count << ", hit_count %: " << hit_count_percent << std::endl;
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
        const int cost = 100 * hit_count;
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

void RunOneGameSimulation(const std::vector<int>& game_symbols)
{
    SlotGameSimulator simulator{
        kGameReels, kGameRows,
        betlines,
        length_based_prizes,
        count_based_prizes
    };

    GameSymbolsGenerator_Const generator{ game_symbols };

    int payout = simulator.RunOneGame(
        generator
    );

    std::cout << payout << std::endl;
}

void RunMultipleGamesSimulation(
    int games_count,
    int start_credit,
    const std::string& credit_out_file
)
{
    SlotGameSimulator simulator{
        kGameReels, kGameRows,
        betlines,
        length_based_prizes,
        count_based_prizes
    };

    FixedProbabilitySymbolGenerator sg1{ sp1 };
    FixedProbabilitySymbolGenerator sg2{ sp2 };
    FixedProbabilitySymbolGenerator sg3{ sp3 };
    FixedProbabilitySymbolGenerator sg4{ sp4 };
    FixedProbabilitySymbolGenerator sg5{ sp5 };

    ReelSymbolsGenerator rg1{ kGameRows, sg1 };
    ReelSymbolsGenerator rg2{ kGameRows, sg2 };
    ReelSymbolsGenerator rg3{ kGameRows, sg3 };
    ReelSymbolsGenerator rg4{ kGameRows, sg4 };
    ReelSymbolsGenerator rg5{ kGameRows, sg5 };

    GameSymbolsGenerator_RSG5 generator{
        kGameReels, kGameRows,
        { &rg1, &rg2, &rg3, &rg4, &rg5 }
    };

    SimulationData simulation_data{
        betlines,
        length_based_prizes,
        count_based_prizes
    };

    simulator.RunMultipleGames(
        games_count,
        generator,
        simulation_data
    );

    OutputSimulationReport(simulation_data);
}

int main(int argc, char* argv[])
{
    int games_count{ 1000000 };
    int start_credit{ 5000000 };
    std::string credit_out_file{ "plik.txt" };  // TODO: Leave it empty!
    std::vector<int> symbols;
    //std::vector<int> symbols{ 0,1,2,3,4,5,5,5,5,5,6,6,6,6,6 };

    const bool args_parsed = ParseArgs(
        argc, argv,
        games_count,
        start_credit,
        credit_out_file,
        symbols
    );

    if(!args_parsed)
    {
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
