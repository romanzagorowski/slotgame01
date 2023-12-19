#pragma once

#include <vector>

// Wyprowadzony z 00
// Zabieram z symbolu '0' 10% i rozkladam pomiedzy 1, 2, 3, 4 odpowiednio 4, 2, 2, 2 (tak bylo w 03)
// Zabieram z symbolu '0' 5% i rozkladam pomiedzy 1, 2, 3, 4 odpowiednio 2, 1, 1, 1
// Zabieram z symbolu '0' 7.5% i rozkladam pomiedzy 1, 2, 3, 4 odpowiednio 3, 1.5, 1.5, 1.5

namespace SymbolProbabilities04
{
    const std::vector<int>& sp1
    {
         50,

        155,

        140,
        140,
        140,

        125,
        125,

        125,
    };

    const std::vector<int>& sp2
    {
         50,

        155,

        140,
        140,
        140,

        125,
        125,

        125,
    };

    const std::vector<int>& sp3
    {
         50,

        155,

        140,
        140,
        140,

        125,
        125,

        125,
    };

    const std::vector<int>& sp4
    {
         50,

        155,

        140,
        140,
        140,

        125,
        125,

        125,
    };

    const std::vector<int>& sp5
    {
         50,

        155,

        140,
        140,
        140,

        125,
        125,

        125,
    };
}

/*
all_games: 100000
won_games: 27820
hf: 27.82
total_payout_amount: 12983350
bet_amount: 10000000
rtp: 129.83
betline:  1, hit_count: 3896, hit_count %: 5.11
betline:  2, hit_count: 3788, hit_count %: 4.97
betline:  3, hit_count: 3883, hit_count %: 5.09
betline:  4, hit_count: 3885, hit_count %: 5.10
betline:  5, hit_count: 3793, hit_count %: 4.98
betline:  6, hit_count: 3727, hit_count %: 4.89
betline:  7, hit_count: 3854, hit_count %: 5.06
betline:  8, hit_count: 3821, hit_count %: 5.01
betline:  9, hit_count: 3806, hit_count %: 4.99
betline: 10, hit_count: 3842, hit_count %: 5.04
betline: 11, hit_count: 3727, hit_count %: 4.89
betline: 12, hit_count: 3727, hit_count %: 4.89
betline: 13, hit_count: 3793, hit_count %: 4.98
betline: 14, hit_count: 3793, hit_count %: 4.98
betline: 15, hit_count: 3805, hit_count %: 4.99
betline: 16, hit_count: 3766, hit_count %: 4.94
betline: 17, hit_count: 3806, hit_count %: 4.99
betline: 18, hit_count: 3842, hit_count %: 5.04
betline: 19, hit_count: 3883, hit_count %: 5.09
betline: 20, hit_count: 3788, hit_count %: 4.97

symbol: 1, length: 2, hit_count: 40834, hit_count %: 53.57, amount: 1020850, amount %:  8.28, total amount %:  7.86
symbol: 1, length: 3, hit_count:  6409, hit_count %:  8.41, amount:  640900, amount %:  5.20, total amount %:  4.94
symbol: 1, length: 4, hit_count:   971, hit_count %:  1.27, amount:  242750, amount %:  1.97, total amount %:  1.87
symbol: 1, length: 5, hit_count:   192, hit_count %:  0.25, amount:  192000, amount %:  1.56, total amount %:  1.48
symbol: 2, length: 3, hit_count:  4613, hit_count %:  6.05, amount:  461300, amount %:  3.74, total amount %:  3.55
symbol: 2, length: 4, hit_count:   681, hit_count %:  0.89, amount:  170250, amount %:  1.38, total amount %:  1.31
symbol: 2, length: 5, hit_count:   111, hit_count %:  0.15, amount:  111000, amount %:  0.90, total amount %:  0.85
symbol: 3, length: 3, hit_count:  4665, hit_count %:  6.12, amount:  466500, amount %:  3.78, total amount %:  3.59
symbol: 3, length: 4, hit_count:   672, hit_count %:  0.88, amount:  168000, amount %:  1.36, total amount %:  1.29
symbol: 3, length: 5, hit_count:   109, hit_count %:  0.14, amount:  109000, amount %:  0.88, total amount %:  0.84
symbol: 4, length: 3, hit_count:  4767, hit_count %:  6.25, amount:  476700, amount %:  3.87, total amount %:  3.67
symbol: 4, length: 4, hit_count:   631, hit_count %:  0.83, amount:  157750, amount %:  1.28, total amount %:  1.22
symbol: 4, length: 5, hit_count:   112, hit_count %:  0.15, amount:  112000, amount %:  0.91, total amount %:  0.86
symbol: 5, length: 3, hit_count:  3429, hit_count %:  4.50, amount:  857250, amount %:  6.95, total amount %:  6.60
symbol: 5, length: 4, hit_count:   445, hit_count %:  0.58, amount:  445000, amount %:  3.61, total amount %:  3.43
symbol: 5, length: 5, hit_count:    56, hit_count %:  0.07, amount:  140000, amount %:  1.14, total amount %:  1.08
symbol: 6, length: 3, hit_count:  3354, hit_count %:  4.40, amount:  838500, amount %:  6.80, total amount %:  6.46
symbol: 6, length: 4, hit_count:   407, hit_count %:  0.53, amount:  407000, amount %:  3.30, total amount %:  3.13
symbol: 6, length: 5, hit_count:    47, hit_count %:  0.06, amount:  117500, amount %:  0.95, total amount %:  0.91
symbol: 7, length: 3, hit_count:  3259, hit_count %:  4.28, amount: 1629500, amount %: 13.22, total amount %: 12.55
symbol: 7, length: 4, hit_count:   398, hit_count %:  0.52, amount: 1990000, amount %: 16.14, total amount %: 15.33
symbol: 7, length: 5, hit_count:    63, hit_count %:  0.08, amount: 1575000, amount %: 12.78, total amount %: 12.13

symbol: 0,  count: 3, hit_count:  2198, hit_count %: 92.01, amount:  439600, amount %: 67.16, total amount %:  3.39
symbol: 0,  count: 4, hit_count:   185, hit_count %:  7.74, amount:  185000, amount %: 28.26, total amount %:  1.42
symbol: 0,  count: 5, hit_count:     6, hit_count %:  0.25, amount:   30000, amount %:  4.58, total amount %:  0.23
*/

// Niezle...
// 0 x 5 trafione 6 razy...
// Na 7 duzy 'total amount %'...
