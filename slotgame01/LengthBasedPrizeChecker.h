#pragma once

#include "BetLine.h"
#include "GameBoard.h"
#include "LengthBasedPrize.h"
#include "LengthBasedPayout.h"

#include <vector>
#include <map>
#include <optional>
#include <cassert>

// Checks vector of length based prizes (fruits like) against a bet line(s).

class LengthBasedPrizeChecker
{
    std::map<std::pair<int, int>, int> map; // (symbol, length) -> prize

    void PopulateMap(const std::vector<LengthBasedPrize>& prizes)
    {
        for(auto& prize : prizes)
        {
            this->map[std::make_pair(prize.symbol, prize.length)] = prize.amount;
        }
    }

public:
    LengthBasedPrizeChecker(const std::vector<LengthBasedPrize>& prizes)
    {
        this->PopulateMap(prizes);
    }

public:
    std::optional<LengthBasedPayout> CheckBetLine(
        const BetLine& betline,
        const GameBoard& board
        )
    {
        const auto symbols = betline.GetSymbols(board);

        const int& first_symbol = symbols[0];
        const int length = CountPrefixLength(first_symbol, symbols);

        if(auto it = map.find(std::make_pair(first_symbol, length)); it != std::end(map))
        {
            const auto& [symbol, length] = it->first;
            const auto& amount = it->second;

            return std::make_optional<LengthBasedPayout>({ symbol, length, amount, betline.GetId() });
        }

        return std::nullopt;
    }

    std::vector<LengthBasedPayout> CheckBetLines(
        const std::vector<BetLine>& betlines,
        const GameBoard& board
    )
    {
        std::vector<LengthBasedPayout> payouts;

        for(const auto& betline : betlines)
        {
            const auto payout = this->CheckBetLine(betline, board);
            if(payout)
            {
                payouts.push_back(*payout);
            }
        }

        return payouts;
    }

private:
    int CountPrefixLength(int symbol, const std::vector<int>& symbols) const
    {
        int prefix_length = 0;

        for(; prefix_length < symbols.size() && symbols[prefix_length] == symbol; ++prefix_length);

        return prefix_length;
    }
};
