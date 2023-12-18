#include "SlotGameSimulator.h"

#include <iostream>
#include <iomanip>
#include <numeric>

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

void SlotGameSimulator::Spin(const std::vector<int>& symbols)
{
    GameBoard board{
        5, 3,
        symbols
    };

    this->length_based_payouts = lbp_checker.CheckBetLines(this->betlines, board);
    this->count_based_payouts = cbp_checker.CheckGameBoard(board);
}

void SlotGameSimulator::Spin(const SymbolsGenerator& generator)
{
    throw "Not implemented yet";
}

void SlotGameSimulator::Simulate()
{
    throw "Not implemented yet";
}

void SlotGameSimulator::Run(
    int games,
    SymbolsGenerator& generator
)
{
    int won_games = 0;

    int payout_amount = 0;

    for(int g = 0; g < games; ++g)
    {
        GameBoard board{
            5, 3,
            generator.Generate()
        };

        length_based_payouts = lbp_checker.CheckBetLines(this->betlines, board);
        count_based_payouts = cbp_checker.CheckGameBoard(board);

        if(!length_based_payouts.empty() || !count_based_payouts.empty())
        {
            won_games++;
        }

        for(const auto& payout : length_based_payouts)
        {
            payout_amount += payout.amount;
        }

        for(const auto& payout : count_based_payouts)
        {
            payout_amount += payout.amount;
        }

    }

    const double hf = 100.0 * won_games / games;
    const int bet_amount = 100 * games;
    const double rtp = 100.0 * payout_amount / bet_amount;

    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "all_games: " << games << std::endl;
    std::cout << "won_games: " << won_games << std::endl;
    std::cout << "hf: " << hf << std::endl;
    std::cout << "payout_amount: " << payout_amount << std::endl;
    std::cout << "bet_amount: " << bet_amount << std::endl;
    std::cout << "rtp: " << rtp << std::endl;
}
