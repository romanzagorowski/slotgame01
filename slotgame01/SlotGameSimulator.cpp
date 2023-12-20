#include "SlotGameSimulator.h"

#include <iostream>
#include <iomanip>
#include <numeric>
#include <map>
#include <utility>

SlotGameSimulator::SlotGameSimulator(
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

void SlotGameSimulator::RunMultipleGames(
    int games_count,
    GameSymbolsGenerator& generator,
    SimulationData& data
)
{
    for(int g = 0; g < games_count; ++g)
    {
        GameBoard board{
            this->reels, this->rows,
            generator.GenerateSymbols()
        };

        std::vector<LengthBasedPayout> length_based_payouts = lbp_checker.CheckBetLines(betlines, board);
        std::vector<CountBasedPayout>  count_based_payouts = cbp_checker.CheckGameBoard(board);

        data.ProcessGameOutcome(length_based_payouts, count_based_payouts);
    }
}

int SlotGameSimulator::RunOneGame(
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
