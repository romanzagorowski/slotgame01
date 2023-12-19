#pragma once

#include <vector>

// Rownomierny rozklad prawdopodobienstwa - kazdy symbol ma po 12.5%

namespace SymbolProbabilities00
{
    const std::vector<int>& sp1
    {
        125,

        125,

        125,
        125,
        125,

        125,
        125,

        125,
    };

    const std::vector<int>& sp2
    {
        125,

        125,

        125,
        125,
        125,

        125,
        125,

        125,
    };

    const std::vector<int>& sp3
    {
        125,

        125,

        125,
        125,
        125,

        125,
        125,

        125,
    };

    const std::vector<int>& sp4
    {
        125,

        125,

        125,
        125,
        125,

        125,
        125,

        125,
    };

    const std::vector<int>& sp5
    {
        125,

        125,

        125,
        125,
        125,

        125,
        125,

        125,
    };
}

/*
all_games: 100000
won_games: 38202
hf: 38.20
total_payout_amount: 20687150
bet_amount: 10000000
rtp: 206.87
betline:  1, hit_count: 2924, hit_count %: 5.11
betline:  2, hit_count: 2743, hit_count %: 4.79
betline:  3, hit_count: 2957, hit_count %: 5.16
betline:  4, hit_count: 2851, hit_count %: 4.98
betline:  5, hit_count: 2842, hit_count %: 4.96
betline:  6, hit_count: 2852, hit_count %: 4.98
betline:  7, hit_count: 2847, hit_count %: 4.97
betline:  8, hit_count: 2931, hit_count %: 5.12
betline:  9, hit_count: 2771, hit_count %: 4.84
betline: 10, hit_count: 2967, hit_count %: 5.18
betline: 11, hit_count: 2852, hit_count %: 4.98
betline: 12, hit_count: 2852, hit_count %: 4.98
betline: 13, hit_count: 2842, hit_count %: 4.96
betline: 14, hit_count: 2842, hit_count %: 4.96
betline: 15, hit_count: 2859, hit_count %: 4.99
betline: 16, hit_count: 2896, hit_count %: 5.06
betline: 17, hit_count: 2771, hit_count %: 4.84
betline: 18, hit_count: 2967, hit_count %: 5.18
betline: 19, hit_count: 2957, hit_count %: 5.16
betline: 20, hit_count: 2743, hit_count %: 4.79

symbol: 1, length: 2, hit_count: 28560, hit_count %: 49.87, amount:  714000, amount %:  6.16, total amount %:  3.45
symbol: 1, length: 3, hit_count:  3694, hit_count %:  6.45, amount:  369400, amount %:  3.19, total amount %:  1.79
symbol: 1, length: 4, hit_count:   481, hit_count %:  0.84, amount:  120250, amount %:  1.04, total amount %:  0.58
symbol: 1, length: 5, hit_count:    71, hit_count %:  0.12, amount:   71000, amount %:  0.61, total amount %:  0.34
symbol: 2, length: 3, hit_count:  3554, hit_count %:  6.21, amount:  355400, amount %:  3.07, total amount %:  1.72
symbol: 2, length: 4, hit_count:   482, hit_count %:  0.84, amount:  120500, amount %:  1.04, total amount %:  0.58
symbol: 2, length: 5, hit_count:    84, hit_count %:  0.15, amount:   84000, amount %:  0.72, total amount %:  0.41
symbol: 3, length: 3, hit_count:  3463, hit_count %:  6.05, amount:  346300, amount %:  2.99, total amount %:  1.67
symbol: 3, length: 4, hit_count:   476, hit_count %:  0.83, amount:  119000, amount %:  1.03, total amount %:  0.58
symbol: 3, length: 5, hit_count:    63, hit_count %:  0.11, amount:   63000, amount %:  0.54, total amount %:  0.30
symbol: 4, length: 3, hit_count:  3474, hit_count %:  6.07, amount:  347400, amount %:  3.00, total amount %:  1.68
symbol: 4, length: 4, hit_count:   419, hit_count %:  0.73, amount:  104750, amount %:  0.90, total amount %:  0.51
symbol: 4, length: 5, hit_count:    76, hit_count %:  0.13, amount:   76000, amount %:  0.66, total amount %:  0.37
symbol: 5, length: 3, hit_count:  3690, hit_count %:  6.44, amount:  922500, amount %:  7.96, total amount %:  4.46
symbol: 5, length: 4, hit_count:   468, hit_count %:  0.82, amount:  468000, amount %:  4.04, total amount %:  2.26
symbol: 5, length: 5, hit_count:    69, hit_count %:  0.12, amount:  172500, amount %:  1.49, total amount %:  0.83
symbol: 6, length: 3, hit_count:  3615, hit_count %:  6.31, amount:  903750, amount %:  7.80, total amount %:  4.37
symbol: 6, length: 4, hit_count:   506, hit_count %:  0.88, amount:  506000, amount %:  4.37, total amount %:  2.45
symbol: 6, length: 5, hit_count:    77, hit_count %:  0.13, amount:  192500, amount %:  1.66, total amount %:  0.93
symbol: 7, length: 3, hit_count:  3433, hit_count %:  5.99, amount: 1716500, amount %: 14.81, total amount %:  8.30
symbol: 7, length: 4, hit_count:   448, hit_count %:  0.78, amount: 2240000, amount %: 19.33, total amount %: 10.83
symbol: 7, length: 5, hit_count:    63, hit_count %:  0.11, amount: 1575000, amount %: 13.59, total amount %:  7.61

symbol: 0,  count: 3, hit_count: 16142, hit_count %: 78.86, amount: 3228400, amount %: 35.48, total amount %: 15.61
symbol: 0,  count: 4, hit_count:  3941, hit_count %: 19.25, amount: 3941000, amount %: 43.31, total amount %: 19.05
symbol: 0,  count: 5, hit_count:   386, hit_count %:  1.89, amount: 1930000, amount %: 21.21, total amount %:  9.33
*/
