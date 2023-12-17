#include "SlotGameSimulator.h"

SlotGameSimulator::SlotGameSimulator(
    const int cols,
    const int rows,
    const std::vector<BetLine>& bet_lines,
    const std::vector<LengthBasedPrize>& length_based_prizes,
    const std::vector<CountBasedPrize>& count_based_prizes
) :
    cols{cols},
    rows{rows},
    bet_lines{bet_lines},
    length_based_prizes{length_based_prizes},
    count_based_prizes{count_based_prizes}
{
}

void SlotGameSimulator::Spin(const std::vector<int>& symbols)
{
    throw "Not implemented yet";
}

void SlotGameSimulator::Spin(const SymbolsGenerator& generator)
{
    throw "Not implemented yet";
}
