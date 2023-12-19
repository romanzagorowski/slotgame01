#pragma once

#include "BetLine.h"
#include "LengthBasedPrize.h"
#include "CountBasedPrize.h"
#include "CountBasedPayout.h"
#include "LengthBasedPayout.h"
#include "SymbolsGenerator.h"
#include "LengthBasedPrizeChecker.h"
#include "CountBasedPrizeChecker.h"
#include "SymbolsGenerator.h"
#include "GameSymbolsGenerator.h"

#include <vector>
#include <utility>
#include <map>

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

    void Simulate();
    void Run(int games, SymbolsGenerator& generator);
    void Run(int games, GameSymbolsGenerator& generator);

private:

    int cols;   // reels
    int rows;

    // -- input

    const std::vector<BetLine>& betlines;
    const std::vector<LengthBasedPrize>& length_based_prizes;
    const std::vector<CountBasedPrize>& count_based_prizes;

    // -- checkers

    LengthBasedPrizeChecker lbp_checker;
    CountBasedPrizeChecker cbp_checker;

    // -- outcome

    std::vector<LengthBasedPayout> length_based_payouts;
    std::vector<CountBasedPayout>  count_based_payouts;
};

// Stake - stawka
// Bet value - wartosc zakladu
