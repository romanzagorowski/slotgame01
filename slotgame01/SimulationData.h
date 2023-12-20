#pragma once

#include "BetLine.h"
#include "LengthBasedPrize.h"
#include "CountBasedPrize.h"

#include "LengthBasedPayout.h"
#include "CountBasedPayout.h"

#include <map>
#include <vector>
#include <utility>

// Gathers simulation data/outcome.

class SimulationData
{
public:
    SimulationData(
        const std::vector<BetLine>& betlines,
        const std::vector<LengthBasedPrize>& length_based_prizes,
        const std::vector<CountBasedPrize>& count_based_prizes,
        int games_count,
        int start_credit,
        int bet_amount
    ) :
        bet_amount{ bet_amount }
    {
        for(const auto& betline : betlines)
        {
            betline_hits[betline.GetId()] = 0;  // TODO: why GetId() not just id?
        }

        for(const auto& prize : length_based_prizes)
        {
            symbol_length_hits[std::make_pair(prize.symbol, prize.length)] = std::make_pair(0, 0);
        }

        for(const auto& prize : count_based_prizes)
        {
            symbol_count_hits[std::make_pair(prize.symbol, prize.count)] = std::make_pair(0, 0);
        }

        balance_history.reserve(games_count + 1);
        balance_history.push_back(start_credit);
    }

public:
    void ProcessGameOutcome(
        const std::vector<LengthBasedPayout>& length_based_payouts,
        const std::vector<CountBasedPayout>& count_based_payouts
    )
    {
        games_count++;

        if(!length_based_payouts.empty() || !count_based_payouts.empty())
        {
            won_games++;
        }

        int length_based_payout_amount = 0;

        for(const auto& payout : length_based_payouts)
        {
            length_based_payout_amount += payout.amount;
        }

        int count_based_payout_amount = 0;

        for(const auto& payout : count_based_payouts)
        {
            count_based_payout_amount += payout.amount;
        }

        total_payout_amount += length_based_payout_amount;
        total_payout_amount += count_based_payout_amount;

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

        // update balance history
        {
            int last_balance = balance_history.back();
            last_balance -= bet_amount;
            last_balance += length_based_payout_amount;
            last_balance += count_based_payout_amount;
            balance_history.push_back(last_balance);
        }
    }

public:
    std::map<int, int> betline_hits;    // betline -> hit_count
    std::map<std::pair<int, int>, std::pair<int, int>> symbol_length_hits;  // symbol, length -> hit_count, amount
    std::map<std::pair<int, int>, std::pair<int, int>> symbol_count_hits;   // symbol, count -> hit_count, amount

    int games_count{ 0 };
    int won_games{ 0 };
    int total_payout_amount{ 0 };

    std::vector<int> balance_history;
    const int bet_amount;
};
