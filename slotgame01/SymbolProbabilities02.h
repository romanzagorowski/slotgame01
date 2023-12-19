#pragma once

#include <vector>

/*
    Zdejmuje troche prawdopodobienstwa z 7 i rozkladam je rownomiernie na mniej platne symbole...
*/

namespace SymbolProbabilities02
{
    const std::vector<int>& sp1
    {
         25,

        225,

        155,    // !!!
        155,    // !!!
        155,    // !!!

        125,
        125,

         35,    // !!!
    };

    const std::vector<int>& sp2
    {
         25,

        225,

        155,    // !!!
        155,    // !!!
        155,    // !!!

        125,
        125,

         35,    // !!!
    };

    const std::vector<int>& sp3
    {
         25,

        225,

        155,    // !!!
        155,    // !!!
        155,    // !!!

        125,
        125,

         35,    // !!!
    };

    const std::vector<int>& sp4
    {
         25,

        225,

        155,    // !!!
        155,    // !!!
        155,    // !!!

        125,
        125,

         35,    // !!!
    };

    const std::vector<int>& sp5
    {
         25,

        225,

        155,    // !!!
        155,    // !!!
        155,    // !!!

        125,
        125,

         35,    // !!!
    };
}

/*
all_games: 100000
won_games: 37247
hf: 37.25
total_payout_amount: 12044425
bet_amount: 10000000
rtp: 120.44
betline:  1, hit_count: 6672, hit_count %: 5.07
betline:  2, hit_count: 6482, hit_count %: 4.93
betline:  3, hit_count: 6599, hit_count %: 5.02
betline:  4, hit_count: 6636, hit_count %: 5.05
betline:  5, hit_count: 6659, hit_count %: 5.06
betline:  6, hit_count: 6587, hit_count %: 5.01
betline:  7, hit_count: 6484, hit_count %: 4.93
betline:  8, hit_count: 6671, hit_count %: 5.07
betline:  9, hit_count: 6460, hit_count %: 4.91
betline: 10, hit_count: 6512, hit_count %: 4.95
betline: 11, hit_count: 6587, hit_count %: 5.01
betline: 12, hit_count: 6587, hit_count %: 5.01
betline: 13, hit_count: 6659, hit_count %: 5.06
betline: 14, hit_count: 6659, hit_count %: 5.06
betline: 15, hit_count: 6656, hit_count %: 5.06
betline: 16, hit_count: 6553, hit_count %: 4.98
betline: 17, hit_count: 6460, hit_count %: 4.91
betline: 18, hit_count: 6512, hit_count %: 4.95
betline: 19, hit_count: 6599, hit_count %: 5.02
betline: 20, hit_count: 6482, hit_count %: 4.93

symbol: 1, length: 2, hit_count: 78731, hit_count %: 59.86, amount: 1968275, amount %: 16.44, total amount %: 16.34
symbol: 1, length: 3, hit_count: 17842, hit_count %: 13.57, amount: 1784200, amount %: 14.90, total amount %: 14.81
symbol: 1, length: 4, hit_count:  4023, hit_count %:  3.06, amount: 1005750, amount %:  8.40, total amount %:  8.35
symbol: 1, length: 5, hit_count:  1185, hit_count %:  0.90, amount: 1185000, amount %:  9.90, total amount %:  9.84
symbol: 2, length: 3, hit_count:  6112, hit_count %:  4.65, amount:  611200, amount %:  5.10, total amount %:  5.07
symbol: 2, length: 4, hit_count:   966, hit_count %:  0.73, amount:  241500, amount %:  2.02, total amount %:  2.01
symbol: 2, length: 5, hit_count:   142, hit_count %:  0.11, amount:  142000, amount %:  1.19, total amount %:  1.18
symbol: 3, length: 3, hit_count:  6178, hit_count %:  4.70, amount:  617800, amount %:  5.16, total amount %:  5.13
symbol: 3, length: 4, hit_count:   993, hit_count %:  0.76, amount:  248250, amount %:  2.07, total amount %:  2.06
symbol: 3, length: 5, hit_count:   193, hit_count %:  0.15, amount:  193000, amount %:  1.61, total amount %:  1.60
symbol: 4, length: 3, hit_count:  6143, hit_count %:  4.67, amount:  614300, amount %:  5.13, total amount %:  5.10
symbol: 4, length: 4, hit_count:  1030, hit_count %:  0.78, amount:  257500, amount %:  2.15, total amount %:  2.14
symbol: 4, length: 5, hit_count:   185, hit_count %:  0.14, amount:  185000, amount %:  1.55, total amount %:  1.54
symbol: 5, length: 3, hit_count:  3356, hit_count %:  2.55, amount:  839000, amount %:  7.01, total amount %:  6.97
symbol: 5, length: 4, hit_count:   462, hit_count %:  0.35, amount:  462000, amount %:  3.86, total amount %:  3.84
symbol: 5, length: 5, hit_count:    55, hit_count %:  0.04, amount:  137500, amount %:  1.15, total amount %:  1.14
symbol: 6, length: 3, hit_count:  3355, hit_count %:  2.55, amount:  838750, amount %:  7.01, total amount %:  6.96
symbol: 6, length: 4, hit_count:   397, hit_count %:  0.30, amount:  397000, amount %:  3.32, total amount %:  3.30
symbol: 6, length: 5, hit_count:    67, hit_count %:  0.05, amount:  167500, amount %:  1.40, total amount %:  1.39
symbol: 7, length: 3, hit_count:    95, hit_count %:  0.07, amount:   47500, amount %:  0.40, total amount %:  0.39
symbol: 7, length: 4, hit_count:     6, hit_count %:  0.00, amount:   30000, amount %:  0.25, total amount %:  0.25
symbol: 7, length: 5, hit_count:     0, hit_count %:  0.00, amount:       0, amount %:  0.00, total amount %:  0.00

symbol: 0,  count: 3, hit_count:   317, hit_count %: 97.54, amount:   63400, amount %: 88.80, total amount %:  0.53
symbol: 0,  count: 4, hit_count:     8, hit_count %:  2.46, amount:    8000, amount %: 11.20, total amount %:  0.07
symbol: 0,  count: 5, hit_count:     0, hit_count %:  0.00, amount:       0, amount %:  0.00, total amount %:  0.00
*/
