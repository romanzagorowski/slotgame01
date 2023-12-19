#include "SlotGameSimulator.h"

#include <iostream>
#include <iomanip>
#include <numeric>
#include <map>
#include <utility>

SlotGameSimulator::SlotGameSimulator(
    const int cols,
    const int rows,
    const std::vector<BetLine>& betlines,
    const std::vector<LengthBasedPrize>& length_based_prizes,
    const std::vector<CountBasedPrize>& count_based_prizes
) :
    cols{ cols },
    rows{ rows },
    betlines{ betlines },
    length_based_prizes{ length_based_prizes },
    count_based_prizes{ count_based_prizes },
    lbp_checker{ length_based_prizes },
    cbp_checker{ count_based_prizes }
{
}

void SlotGameSimulator::Simulate()
{
    throw "Not implemented yet";
}

void SlotGameSimulator::Run(
    int games,
    GameSymbolsGenerator& generator
)
{
    int won_games = 0;
    int total_payout_amount = 0;

    //---

    std::map<int, int> betline_hits;    // betline -> hit count

    for(const auto& betline : betlines)
    {
        betline_hits[betline.GetId()] = 0;
    }

    //---
    
    std::map<std::pair<int, int>, std::pair<int, int>> symbol_length_hits;

    for(const auto& prize : length_based_prizes)
    {
        symbol_length_hits[std::make_pair(prize.symbol, prize.length)] = std::make_pair(0, 0);
    }

    //--- COUNT based prizes

    std::map<std::pair<int, int>, std::pair<int, int>> symbol_count_hits;

    for(const auto& prize : count_based_prizes)
    {
        symbol_count_hits[std::make_pair(prize.symbol, prize.count)] = std::make_pair(0, 0);
    }

    //---

    for(int g = 0; g < games; ++g)
    {
        GameBoard board{
            5, 3,
            generator.GenerateSymbols()
        };

        length_based_payouts = lbp_checker.CheckBetLines(this->betlines, board);
        count_based_payouts = cbp_checker.CheckGameBoard(board);

        if(!length_based_payouts.empty() || !count_based_payouts.empty())
        {
            won_games++;
        }

        for(const auto& payout : length_based_payouts)
        {
            total_payout_amount += payout.amount;
        }

        for(const auto& payout : count_based_payouts)
        {
            total_payout_amount += payout.amount;
        }

        for(const auto& payout : length_based_payouts)
        {
            betline_hits[payout.betline] += 1;
        }

        for(const auto& payout : length_based_payouts)
        {
            auto& [hit_count, amount] = symbol_length_hits[std::make_pair(payout.symbol, payout.length)];
            
            hit_count += 1;
            amount += payout.amount;
        }

        for(const auto& payout : count_based_payouts)
        {
            auto& [hit_count, amount] = symbol_count_hits[std::make_pair(payout.symbol, payout.count)];

            hit_count += 1;
            amount += payout.amount;
        }
    }

    const double hf = 100.0 * won_games / games;
    const int bet_amount = 100 * games;
    const double rtp = 100.0 * total_payout_amount / bet_amount;

    std::cout << std::setprecision(2) << std::fixed;

    std::cout << "all_games: " << games << std::endl;
    std::cout << "won_games: " << won_games << std::endl;
    std::cout << "hf: " << hf << std::endl;
    std::cout << "total_payout_amount: " << total_payout_amount << std::endl;
    std::cout << "bet_amount: " << bet_amount << std::endl;
    std::cout << "rtp: " << rtp << std::endl;

    //-- betline

    auto total_betline_hit_count = 0;

    for(const auto& [betline, hit_count] : betline_hits)
    {
        total_betline_hit_count += hit_count;
    }

    for(const auto& [betline, hit_count] : betline_hits)
    {
        const double hit_count_percent = 100.0 * hit_count / total_betline_hit_count;

        std::cout << "betline: " << std::setw(2) << betline << ", hit_count: " << hit_count << ", hit_count %: " << hit_count_percent << std::endl;
    }

    //--- symbol LENGTH hit count

    auto total_symbol_length_hit_count = 0;
    auto total_symbol_length_amount = 0;

    for(const auto& [key, value] : symbol_length_hits)
    {
        const auto& [hit_count, amount] = value;

        total_symbol_length_hit_count += hit_count;
        total_symbol_length_amount += amount;
    }

    std::cout << std::endl;

    for(const auto& [key, value] : symbol_length_hits)
    {
        const auto& [symbol, length] = key;
        const auto& [hit_count, amount] = value;

        const double hit_count_percent = 100.0 * hit_count / total_symbol_length_hit_count;
        const double amount_percent = 100.0 * amount / total_symbol_length_amount;
        const double total_amount_percent = 100.0 * amount / total_payout_amount;
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

    for(const auto& [key, value] : symbol_count_hits)
    {
        const auto& [hit_count, amount] = value;

        total_symbol_count_hit_count += hit_count;
        total_symbol_count_amount += amount;
    }

    std::cout << std::endl;

    for(const auto& [key, value] : symbol_count_hits)
    {
        const auto& [symbol, count] = key;
        const auto& [hit_count, amount] = value;

        const double hit_count_percent = 100.0 * hit_count / total_symbol_count_hit_count;
        const double amount_percent = 100.0 * amount / total_symbol_count_amount;
        const double total_amount_percent = 100.0 * amount / total_payout_amount;
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
