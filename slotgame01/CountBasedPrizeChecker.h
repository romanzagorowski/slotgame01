#pragma once

#pragma once

#include "CountBasedPrize.h"
#include "CountBasedPayout.h"
#include "GameBoard.h"

#include <map>
#include <vector>
#include <utility>
#include <optional>
#include <algorithm>

class CountBasedPrizeChecker
{
    std::map<int, std::map<int, int>> map;  // symbol -> count -> prize

    void PopulateMap(const std::vector<CountBasedPrize>& prizes)
    {
        for(auto& prize : prizes)
        {
            this->map[prize.symbol][prize.count] = prize.amount;
        }
    }

public:
    CountBasedPrizeChecker(const std::vector<CountBasedPrize>& prizes)
    {
        this->PopulateMap(prizes);
    }

public:
    std::vector<CountBasedPayout> CheckGameBoard(
        const GameBoard& board
    )
    {
        std::vector<CountBasedPayout> payouts;

        const auto& board_symbols = board.GetSymbols();

        for(const auto& [symbol, inner_map] : this->map)
        {
            const int symbol_count = static_cast<int>(
                std::count(std::begin(board_symbols), std::end(board_symbols), symbol)
                );

            if(auto it = inner_map.find(symbol_count); it != std::end(inner_map))
            {
                const auto& count = it->first;
                const auto& amount = it->second;

                payouts.push_back({ symbol, count, amount });
            }
        }

        return payouts;
    }
};
