#pragma once

#include <vector>

// Five symbol probability vectors for five reels in the game.
// Number of a symbol coresponds to an index in a vector.
// So, sp1[0] is the probability of occurence of the crown (0) symbol on the 1st reel.
//     sp3[7] is the probability of occurence of the seven (7) symbol on the 3rd reel.
// Accuracy is to 1 decimal point, so 50 means 5.0%, 175 means 17.5% and so on.

inline static const std::vector<int>& ___sp1
{
     50,    //  1.0 -  5.0

    175,    //  5.1 - 22.5

    160,    // 22.6 - 38.5
    165,    // 38.6 - 55.0
    165,    // 55.1 - 71.5

    105,    // 71.6 - 82.0
    105,    // 82.1 - 92.5

     75,    // 92.6 - 100.0
};

inline static const std::vector<int>& ___sp2
{
     50,

    185,

    160,
    160,
    160,

    105,
    105,

     75,
};

inline static const std::vector<int>& ___sp3
{
     50,

     65,

    200,
    200,
    200,

    105,
    105,

     75,
};

inline static const std::vector<int>& ___sp4
{
     50,

    175,

    160,
    165,
    165,

    105,
    105,

     75,
};

inline static const std::vector<int>& ___sp5
{
     50,

    175,

    160,
    165,
    165,

    105,
    105,

     75,
};
