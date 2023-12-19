#pragma once

#include <vector>

namespace SymbolProbabilities01
{
    const std::vector<int>& sp1
    {
         25,    // !!!

        225,    // !!!

        125,
        125,
        125,

        125,
        125,

        125,
    };

    const std::vector<int>& sp2
    {
         25,
        225,
        125,
        125,
        125,
        125,
        125,
        125,
    };

    const std::vector<int>& sp3
    {
         25,
        225,
        125,
        125,
        125,
        125,
        125,
        125,
    };

    const std::vector<int>& sp4
    {
         25,
        225,
        125,
        125,
        125,
        125,
        125,
        125,
    };

    const std::vector<int>& sp5
    {
         25,
        225,
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
won_games: 35266
hf: 35.27
total_payout_amount: 15706100
bet_amount: 10000000
rtp: 157.06
betline:  1, hit_count: 6203, hit_count %: 4.94
betline:  2, hit_count: 6284, hit_count %: 5.01
betline:  3, hit_count: 6249, hit_count %: 4.98
betline:  4, hit_count: 6244, hit_count %: 4.97
betline:  5, hit_count: 6184, hit_count %: 4.93
betline:  6, hit_count: 6392, hit_count %: 5.09
betline:  7, hit_count: 6263, hit_count %: 4.99
betline:  8, hit_count: 6255, hit_count %: 4.98
betline:  9, hit_count: 6265, hit_count %: 4.99
betline: 10, hit_count: 6310, hit_count %: 5.03
betline: 11, hit_count: 6392, hit_count %: 5.09
betline: 12, hit_count: 6392, hit_count %: 5.09
betline: 13, hit_count: 6184, hit_count %: 4.93
betline: 14, hit_count: 6184, hit_count %: 4.93
betline: 15, hit_count: 6212, hit_count %: 4.95
betline: 16, hit_count: 6391, hit_count %: 5.09
betline: 17, hit_count: 6265, hit_count %: 4.99
betline: 18, hit_count: 6310, hit_count %: 5.03
betline: 19, hit_count: 6249, hit_count %: 4.98
betline: 20, hit_count: 6284, hit_count %: 5.01

symbol: 1, length: 2, hit_count: 78824, hit_count %: 62.80, amount: 1970600, amount %: 12.61, total amount %: 12.55
symbol: 1, length: 3, hit_count: 17686, hit_count %: 14.09, amount: 1768600, amount %: 11.32, total amount %: 11.26
symbol: 1, length: 4, hit_count:  3864, hit_count %:  3.08, amount:  966000, amount %:  6.18, total amount %:  6.15
symbol: 1, length: 5, hit_count:  1169, hit_count %:  0.93, amount: 1169000, amount %:  7.48, total amount %:  7.44
symbol: 2, length: 3, hit_count:  3328, hit_count %:  2.65, amount:  332800, amount %:  2.13, total amount %:  2.12
symbol: 2, length: 4, hit_count:   395, hit_count %:  0.31, amount:   98750, amount %:  0.63, total amount %:  0.63
symbol: 2, length: 5, hit_count:    61, hit_count %:  0.05, amount:   61000, amount %:  0.39, total amount %:  0.39
symbol: 3, length: 3, hit_count:  3546, hit_count %:  2.83, amount:  354600, amount %:  2.27, total amount %:  2.26
symbol: 3, length: 4, hit_count:   443, hit_count %:  0.35, amount:  110750, amount %:  0.71, total amount %:  0.71
symbol: 3, length: 5, hit_count:    57, hit_count %:  0.05, amount:   57000, amount %:  0.36, total amount %:  0.36
symbol: 4, length: 3, hit_count:  3516, hit_count %:  2.80, amount:  351600, amount %:  2.25, total amount %:  2.24
symbol: 4, length: 4, hit_count:   427, hit_count %:  0.34, amount:  106750, amount %:  0.68, total amount %:  0.68
symbol: 4, length: 5, hit_count:    55, hit_count %:  0.04, amount:   55000, amount %:  0.35, total amount %:  0.35
symbol: 5, length: 3, hit_count:  3565, hit_count %:  2.84, amount:  891250, amount %:  5.70, total amount %:  5.67
symbol: 5, length: 4, hit_count:   423, hit_count %:  0.34, amount:  423000, amount %:  2.71, total amount %:  2.69
symbol: 5, length: 5, hit_count:    54, hit_count %:  0.04, amount:  135000, amount %:  0.86, total amount %:  0.86
symbol: 6, length: 3, hit_count:  3558, hit_count %:  2.83, amount:  889500, amount %:  5.69, total amount %:  5.66
symbol: 6, length: 4, hit_count:   417, hit_count %:  0.33, amount:  417000, amount %:  2.67, total amount %:  2.66
symbol: 6, length: 5, hit_count:    62, hit_count %:  0.05, amount:  155000, amount %:  0.99, total amount %:  0.99
symbol: 7, length: 3, hit_count:  3541, hit_count %:  2.82, amount: 1770500, amount %: 11.33, total amount %: 11.27
symbol: 7, length: 4, hit_count:   474, hit_count %:  0.38, amount: 2370000, amount %: 15.16, total amount %: 15.09
symbol: 7, length: 5, hit_count:    47, hit_count %:  0.04, amount: 1175000, amount %:  7.52, total amount %:  7.48

symbol: 0,  count: 3, hit_count:   342, hit_count %: 97.44, amount:   68400, amount %: 88.37, total amount %:  0.44
symbol: 0,  count: 4, hit_count:     9, hit_count %:  2.56, amount:    9000, amount %: 11.63, total amount %:  0.06
symbol: 0,  count: 5, hit_count:     0, hit_count %:  0.00, amount:       0, amount %:  0.00, total amount %:  0.00
*/
