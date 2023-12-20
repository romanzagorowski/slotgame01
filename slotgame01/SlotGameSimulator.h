#pragma once

#include "BetLine.h"
#include "LengthBasedPrize.h"
#include "CountBasedPrize.h"
#include "CountBasedPayout.h"
#include "LengthBasedPayout.h"
#include "LengthBasedPrizeChecker.h"
#include "CountBasedPrizeChecker.h"
#include "GameSymbolsGenerator.h"
#include "SimulationData.h"

#include <vector>
#include <utility>
#include <map>

// A slots game simulator.
// Runs simulation of one game or multiple games.

class SlotGameSimulator
{
public:
    SlotGameSimulator(
        const int reels,
        const int rows,
        const std::vector<BetLine>& betlines,
        const std::vector<LengthBasedPrize>& length_based_prizes,
        const std::vector<CountBasedPrize>& count_based_prizes
    ) :
        reels{ reels },
        rows{ rows },
        betlines{ betlines },
        length_based_prizes{ length_based_prizes },
        count_based_prizes{ count_based_prizes },
        lbp_checker{ length_based_prizes },
        cbp_checker{ count_based_prizes }
    {
    }

    void RunMultipleGames(
        int games_count,
        GameSymbolsGenerator& generator,
        SimulationData& data
    )
    {
        for(int g = 0; g < games_count; ++g)
        {
            GameBoard board{
                reels, rows,
                generator.GenerateSymbols()
            };

            std::vector<LengthBasedPayout> length_based_payouts = lbp_checker.CheckBetLines(betlines, board);
            std::vector<CountBasedPayout>  count_based_payouts = cbp_checker.CheckGameBoard(board);

            data.ProcessGameOutcome(length_based_payouts, count_based_payouts);
        }
    }

    int RunOneGame(
        GameSymbolsGenerator& generator
    )
    {
        GameBoard board{
            reels, rows,
            generator.GenerateSymbols()
        };

        std::vector<LengthBasedPayout> length_based_payouts = lbp_checker.CheckBetLines(betlines, board);
        std::vector<CountBasedPayout>  count_based_payouts = cbp_checker.CheckGameBoard(board);

        int total_payout = 0;

        for(const auto& payout : length_based_payouts)
        {
            total_payout += payout.amount;
        }

        for(const auto& payout : count_based_payouts)
        {
            total_payout += payout.amount;
        }

        return total_payout;
    }

private:

    const int reels;
    const int rows;

    // -- input

    const std::vector<BetLine>& betlines;
    const std::vector<LengthBasedPrize>& length_based_prizes;
    const std::vector<CountBasedPrize>& count_based_prizes;

    // -- checkers

    LengthBasedPrizeChecker lbp_checker;
    CountBasedPrizeChecker cbp_checker;
};
