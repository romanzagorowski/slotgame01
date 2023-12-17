#include "SlotGameSimulator.h"
#include "BetLines.h"
#include "CountBasedPrizes.h"
#include "LengthBasedPrizes.h"

#include "LengthBasedPrizeChecker.h"
#include "CountBasedPrizeChecker.h"

#include <vector>

int main()
{
    const std::vector symbols{ 0,1,2,3,4,5,5,5,5,5,6,6,6,6,6 };

    SlotGameSimulator simulator{
        5, 3, 
        betlines, 
        length_based_prizes,
        count_based_prizes
    };
}
