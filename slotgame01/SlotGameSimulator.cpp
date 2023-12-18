#include "SlotGameSimulator.h"

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
