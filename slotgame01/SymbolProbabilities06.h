#pragma once

#include <vector>

// Wyprowadzony z 05
// Z 6 i 7 przenosze na 1, 2, 3, 4 

namespace SymbolProbabilities06
{
    const std::vector<int>& sp1
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

    const std::vector<int>& sp2
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

    const std::vector<int>& sp3
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

    const std::vector<int>& sp4
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

    const std::vector<int>& sp5
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
}

/*
all_games: 100000
won_games: 32319
hf: 32.32
total_payout_amount: 9721600
bet_amount: 10000000
rtp: 97.22
betline:  1, hit_count: 5018, hit_count %: 5.14
betline:  2, hit_count: 4756, hit_count %: 4.87
betline:  3, hit_count: 4956, hit_count %: 5.07
betline:  4, hit_count: 4973, hit_count %: 5.09
betline:  5, hit_count: 4894, hit_count %: 5.01
betline:  6, hit_count: 4864, hit_count %: 4.98
betline:  7, hit_count: 4860, hit_count %: 4.97
betline:  8, hit_count: 4903, hit_count %: 5.02
betline:  9, hit_count: 4823, hit_count %: 4.94
betline: 10, hit_count: 4949, hit_count %: 5.06
betline: 11, hit_count: 4864, hit_count %: 4.98
betline: 12, hit_count: 4864, hit_count %: 4.98
betline: 13, hit_count: 4894, hit_count %: 5.01
betline: 14, hit_count: 4894, hit_count %: 5.01
betline: 15, hit_count: 4873, hit_count %: 4.99
betline: 16, hit_count: 4851, hit_count %: 4.96
betline: 17, hit_count: 4823, hit_count %: 4.94
betline: 18, hit_count: 4949, hit_count %: 5.06
betline: 19, hit_count: 4956, hit_count %: 5.07
betline: 20, hit_count: 4756, hit_count %: 4.87

symbol: 1, length: 2, hit_count: 55368, hit_count %: 56.66, amount: 1384200, amount %: 15.21, total amount %: 14.24
symbol: 1, length: 3, hit_count: 10292, hit_count %: 10.53, amount: 1029200, amount %: 11.31, total amount %: 10.59
symbol: 1, length: 4, hit_count:  1921, hit_count %:  1.97, amount:  480250, amount %:  5.28, total amount %:  4.94
symbol: 1, length: 5, hit_count:   455, hit_count %:  0.47, amount:  455000, amount %:  5.00, total amount %:  4.68
symbol: 2, length: 3, hit_count:  6694, hit_count %:  6.85, amount:  669400, amount %:  7.35, total amount %:  6.89
symbol: 2, length: 4, hit_count:  1115, hit_count %:  1.14, amount:  278750, amount %:  3.06, total amount %:  2.87
symbol: 2, length: 5, hit_count:   186, hit_count %:  0.19, amount:  186000, amount %:  2.04, total amount %:  1.91
symbol: 3, length: 3, hit_count:  6985, hit_count %:  7.15, amount:  698500, amount %:  7.67, total amount %:  7.19
symbol: 3, length: 4, hit_count:  1065, hit_count %:  1.09, amount:  266250, amount %:  2.93, total amount %:  2.74
symbol: 3, length: 5, hit_count:   197, hit_count %:  0.20, amount:  197000, amount %:  2.16, total amount %:  2.03
symbol: 4, length: 3, hit_count:  6811, hit_count %:  6.97, amount:  681100, amount %:  7.48, total amount %:  7.01
symbol: 4, length: 4, hit_count:  1138, hit_count %:  1.16, amount:  284500, amount %:  3.13, total amount %:  2.93
symbol: 4, length: 5, hit_count:   196, hit_count %:  0.20, amount:  196000, amount %:  2.15, total amount %:  2.02
symbol: 5, length: 3, hit_count:  1908, hit_count %:  1.95, amount:  477000, amount %:  5.24, total amount %:  4.91
symbol: 5, length: 4, hit_count:   178, hit_count %:  0.18, amount:  178000, amount %:  1.96, total amount %:  1.83
symbol: 5, length: 5, hit_count:    18, hit_count %:  0.02, amount:   45000, amount %:  0.49, total amount %:  0.46
symbol: 6, length: 3, hit_count:  2109, hit_count %:  2.16, amount:  527250, amount %:  5.79, total amount %:  5.42
symbol: 6, length: 4, hit_count:   204, hit_count %:  0.21, amount:  204000, amount %:  2.24, total amount %:  2.10
symbol: 6, length: 5, hit_count:    27, hit_count %:  0.03, amount:   67500, amount %:  0.74, total amount %:  0.69
symbol: 7, length: 3, hit_count:   793, hit_count %:  0.81, amount:  396500, amount %:  4.36, total amount %:  4.08
symbol: 7, length: 4, hit_count:    55, hit_count %:  0.06, amount:  275000, amount %:  3.02, total amount %:  2.83
symbol: 7, length: 5, hit_count:     5, hit_count %:  0.01, amount:  125000, amount %:  1.37, total amount %:  1.29

symbol: 0,  count: 3, hit_count:  2126, hit_count %: 92.23, amount:  425200, amount %: 68.56, total amount %:  4.37
symbol: 0,  count: 4, hit_count:   175, hit_count %:  7.59, amount:  175000, amount %: 28.22, total amount %:  1.80
symbol: 0,  count: 5, hit_count:     4, hit_count %:  0.17, amount:   20000, amount %:  3.22, total amount %:  0.21
*/

// Niezle...
// rtp musze zbic ponizej 98...
