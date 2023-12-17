#pragma once

#include "BetLine.h"
#include "LengthBasedPrize.h"
#include "CountBasedPrize.h"
#include "CountBasedPayout.h"
#include "LengthBasedPayout.h"
#include "SymbolGenerator.h"

#include <vector>
#include <utility>
#include <map>

//struct LengthBasedPrize
//{
//    int length;
//    int prize;
//};
//
//std::map<int, std::vector<LengthBasedPrize>> m1;

// Co zapewnia, ze korona jest tylko na jednej rolce? Generator symboli dla rolki?

class SlotGameSimulator
{
public:
    SlotGameSimulator(
        const int cols,
        const int rows,
        const std::vector<BetLine>& betlines,
        const std::vector<LengthBasedPrize>& length_based_prizes,
        const std::vector<CountBasedPrize>& count_based_prizes
    );

    void Spin(const std::vector<int>& symbols);
    void Spin(const SymbolsGenerator& generator);

    // -- input

    const std::vector<BetLine>& bet_lines;
    const std::vector<LengthBasedPrize>& length_based_prizes;
    const std::vector<CountBasedPrize>& count_based_prizes;

    int cols;   // reels
    int rows;

    // -- outcome

    std::vector<LengthBasedPayout> length_based_payouts;
    std::vector<CountBasedPayout>  count_based_payouts;
};

// Stake - stawka
// Bet value - wartosc zakladu
