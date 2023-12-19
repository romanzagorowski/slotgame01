#pragma once

#include <vector>

// Wyprowadzony z 00
// Zabieram z symbolu '0' 10% i rozkladam pomiedzy 1, 2, 3, 4 odpowiednio 4, 2, 2, 2

namespace SymbolProbabilities03
{
    const std::vector<int>& sp1
    {
         25,

        165,

        145,
        145,
        145,

        125,
        125,

        125,
    };

    const std::vector<int>& sp2
    {
         25,

        165,

        145,
        145,
        145,

        125,
        125,

        125,
    };

    const std::vector<int>& sp3
    {
         25,

        165,

        145,
        145,
        145,

        125,
        125,

        125,
    };

    const std::vector<int>& sp4
    {
         25,

        165,

        145,
        145,
        145,

        125,
        125,

        125,
    };

    const std::vector<int>& sp5
    {
         25,

        165,

        145,
        145,
        145,

        125,
        125,

        125,
    };
}

/*
all_games: 100000
won_games: 28353
hf: 28.35
total_payout_amount: 13614575
bet_amount: 10000000
rtp: 136.15
betline:  1, hit_count: 4198, hit_count %: 4.94
betline:  2, hit_count: 4319, hit_count %: 5.09
betline:  3, hit_count: 4244, hit_count %: 5.00
betline:  4, hit_count: 4261, hit_count %: 5.02
betline:  5, hit_count: 4245, hit_count %: 5.00
betline:  6, hit_count: 4238, hit_count %: 4.99
betline:  7, hit_count: 4150, hit_count %: 4.89
betline:  8, hit_count: 4251, hit_count %: 5.01
betline:  9, hit_count: 4262, hit_count %: 5.02
betline: 10, hit_count: 4253, hit_count %: 5.01
betline: 11, hit_count: 4238, hit_count %: 4.99
betline: 12, hit_count: 4238, hit_count %: 4.99
betline: 13, hit_count: 4245, hit_count %: 5.00
betline: 14, hit_count: 4245, hit_count %: 5.00
betline: 15, hit_count: 4215, hit_count %: 4.96
betline: 16, hit_count: 4228, hit_count %: 4.98
betline: 17, hit_count: 4262, hit_count %: 5.02
betline: 18, hit_count: 4253, hit_count %: 5.01
betline: 19, hit_count: 4244, hit_count %: 5.00
betline: 20, hit_count: 4319, hit_count %: 5.09

symbol: 1, length: 2, hit_count: 45883, hit_count %: 54.04, amount: 1147075, amount %:  8.47, total amount %:  8.43
symbol: 1, length: 3, hit_count:  7485, hit_count %:  8.82, amount:  748500, amount %:  5.53, total amount %:  5.50
symbol: 1, length: 4, hit_count:  1243, hit_count %:  1.46, amount:  310750, amount %:  2.30, total amount %:  2.28
symbol: 1, length: 5, hit_count:   229, hit_count %:  0.27, amount:  229000, amount %:  1.69, total amount %:  1.68
symbol: 2, length: 3, hit_count:  5182, hit_count %:  6.10, amount:  518200, amount %:  3.83, total amount %:  3.81
symbol: 2, length: 4, hit_count:   742, hit_count %:  0.87, amount:  185500, amount %:  1.37, total amount %:  1.36
symbol: 2, length: 5, hit_count:   149, hit_count %:  0.18, amount:  149000, amount %:  1.10, total amount %:  1.09
symbol: 3, length: 3, hit_count:  5291, hit_count %:  6.23, amount:  529100, amount %:  3.91, total amount %:  3.89
symbol: 3, length: 4, hit_count:   725, hit_count %:  0.85, amount:  181250, amount %:  1.34, total amount %:  1.33
symbol: 3, length: 5, hit_count:   117, hit_count %:  0.14, amount:  117000, amount %:  0.86, total amount %:  0.86
symbol: 4, length: 3, hit_count:  5222, hit_count %:  6.15, amount:  522200, amount %:  3.86, total amount %:  3.84
symbol: 4, length: 4, hit_count:   756, hit_count %:  0.89, amount:  189000, amount %:  1.40, total amount %:  1.39
symbol: 4, length: 5, hit_count:   125, hit_count %:  0.15, amount:  125000, amount %:  0.92, total amount %:  0.92
symbol: 5, length: 3, hit_count:  3419, hit_count %:  4.03, amount:  854750, amount %:  6.31, total amount %:  6.28
symbol: 5, length: 4, hit_count:   421, hit_count %:  0.50, amount:  421000, amount %:  3.11, total amount %:  3.09
symbol: 5, length: 5, hit_count:    57, hit_count %:  0.07, amount:  142500, amount %:  1.05, total amount %:  1.05
symbol: 6, length: 3, hit_count:  3559, hit_count %:  4.19, amount:  889750, amount %:  6.57, total amount %:  6.54
symbol: 6, length: 4, hit_count:   431, hit_count %:  0.51, amount:  431000, amount %:  3.18, total amount %:  3.17
symbol: 6, length: 5, hit_count:    62, hit_count %:  0.07, amount:  155000, amount %:  1.15, total amount %:  1.14
symbol: 7, length: 3, hit_count:  3280, hit_count %:  3.86, amount: 1640000, amount %: 12.12, total amount %: 12.05
symbol: 7, length: 4, hit_count:   460, hit_count %:  0.54, amount: 2300000, amount %: 16.99, total amount %: 16.89
symbol: 7, length: 5, hit_count:    70, hit_count %:  0.08, amount: 1750000, amount %: 12.93, total amount %: 12.85

symbol: 0,  count: 3, hit_count:   330, hit_count %: 96.21, amount:   66000, amount %: 83.54, total amount %:  0.48
symbol: 0,  count: 4, hit_count:    13, hit_count %:  3.79, amount:   13000, amount %: 16.46, total amount %:  0.10
symbol: 0,  count: 5, hit_count:     0, hit_count %:  0.00, amount:       0, amount %:  0.00, total amount %:  0.00
*/

// Niezle
// Ale 0 x 5 nie wypadlo ani razu...
// Nadal 7 stanowi duzy procent wygranych...
