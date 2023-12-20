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

// Co zapewnia, ze korona jest tylko na jednej rolce? Generator symboli dla rolki?

class SlotGameSimulator
{
public:
    SlotGameSimulator(
        const int reels,
        const int rows,
        const std::vector<BetLine>& betlines,
        const std::vector<LengthBasedPrize>& length_based_prizes,
        const std::vector<CountBasedPrize>& count_based_prizes
    );

    void RunMultipleGames(int games_count, GameSymbolsGenerator& generator, SimulationData& data);
    int RunOneGame(GameSymbolsGenerator& generator);

private:

    int reels;
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
