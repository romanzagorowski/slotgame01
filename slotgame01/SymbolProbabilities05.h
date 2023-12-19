#pragma once

#include <vector>

// Wyprowadzony z 04
// Z '7' zabieram 5% i rozkladam na 1, 2, 3, 4 po 2, 1, 1, 1

namespace SymbolProbabilities05
{
    const std::vector<int>& sp1
    {
         50,

        175,

        150,
        150,
        150,

        125,
        125,

         75,
    };

    const std::vector<int>& sp2
    {
         50,

        175,

        150,
        150,
        150,

        125,
        125,

         75,
    };

    const std::vector<int>& sp3
    {
         50,

        175,

        150,
        150,
        150,

        125,
        125,

         75,
    };

    const std::vector<int>& sp4
    {
         50,

        175,

        150,
        150,
        150,

        125,
        125,

         75,
    };

    const std::vector<int>& sp5
    {
         50,

        175,

        150,
        150,
        150,

        125,
        125,

         75,
    };
}

/*
all_games: 100000
won_games: 30957
hf: 30.96
total_payout_amount: 9975625
bet_amount: 10000000
rtp: 99.76
betline:  1, hit_count: 4535, hit_count %: 5.00
betline:  2, hit_count: 4513, hit_count %: 4.98
betline:  3, hit_count: 4594, hit_count %: 5.07
betline:  4, hit_count: 4469, hit_count %: 4.93
betline:  5, hit_count: 4598, hit_count %: 5.07
betline:  6, hit_count: 4475, hit_count %: 4.94
betline:  7, hit_count: 4520, hit_count %: 4.99
betline:  8, hit_count: 4515, hit_count %: 4.98
betline:  9, hit_count: 4468, hit_count %: 4.93
betline: 10, hit_count: 4603, hit_count %: 5.08
betline: 11, hit_count: 4475, hit_count %: 4.94
betline: 12, hit_count: 4475, hit_count %: 4.94
betline: 13, hit_count: 4598, hit_count %: 5.07
betline: 14, hit_count: 4598, hit_count %: 5.07
betline: 15, hit_count: 4492, hit_count %: 4.96
betline: 16, hit_count: 4510, hit_count %: 4.98
betline: 17, hit_count: 4468, hit_count %: 4.93
betline: 18, hit_count: 4603, hit_count %: 5.08
betline: 19, hit_count: 4594, hit_count %: 5.07
betline: 20, hit_count: 4513, hit_count %: 4.98

symbol: 1, length: 2, hit_count: 50973, hit_count %: 56.25, amount: 1274325, amount %: 13.66, total amount %: 12.77
symbol: 1, length: 3, hit_count:  8851, hit_count %:  9.77, amount:  885100, amount %:  9.49, total amount %:  8.87
symbol: 1, length: 4, hit_count:  1551, hit_count %:  1.71, amount:  387750, amount %:  4.16, total amount %:  3.89
symbol: 1, length: 5, hit_count:   312, hit_count %:  0.34, amount:  312000, amount %:  3.34, total amount %:  3.13
symbol: 2, length: 3, hit_count:  5555, hit_count %:  6.13, amount:  555500, amount %:  5.95, total amount %:  5.57
symbol: 2, length: 4, hit_count:   863, hit_count %:  0.95, amount:  215750, amount %:  2.31, total amount %:  2.16
symbol: 2, length: 5, hit_count:   156, hit_count %:  0.17, amount:  156000, amount %:  1.67, total amount %:  1.56
symbol: 3, length: 3, hit_count:  5786, hit_count %:  6.39, amount:  578600, amount %:  6.20, total amount %:  5.80
symbol: 3, length: 4, hit_count:   834, hit_count %:  0.92, amount:  208500, amount %:  2.23, total amount %:  2.09
symbol: 3, length: 5, hit_count:   150, hit_count %:  0.17, amount:  150000, amount %:  1.61, total amount %:  1.50
symbol: 4, length: 3, hit_count:  5797, hit_count %:  6.40, amount:  579700, amount %:  6.21, total amount %:  5.81
symbol: 4, length: 4, hit_count:   855, hit_count %:  0.94, amount:  213750, amount %:  2.29, total amount %:  2.14
symbol: 4, length: 5, hit_count:   136, hit_count %:  0.15, amount:  136000, amount %:  1.46, total amount %:  1.36
symbol: 5, length: 3, hit_count:  3424, hit_count %:  3.78, amount:  856000, amount %:  9.18, total amount %:  8.58
symbol: 5, length: 4, hit_count:   450, hit_count %:  0.50, amount:  450000, amount %:  4.82, total amount %:  4.51
symbol: 5, length: 5, hit_count:    48, hit_count %:  0.05, amount:  120000, amount %:  1.29, total amount %:  1.20
symbol: 6, length: 3, hit_count:  3477, hit_count %:  3.84, amount:  869250, amount %:  9.32, total amount %:  8.71
symbol: 6, length: 4, hit_count:   421, hit_count %:  0.46, amount:  421000, amount %:  4.51, total amount %:  4.22
symbol: 6, length: 5, hit_count:    63, hit_count %:  0.07, amount:  157500, amount %:  1.69, total amount %:  1.58
symbol: 7, length: 3, hit_count:   855, hit_count %:  0.94, amount:  427500, amount %:  4.58, total amount %:  4.29
symbol: 7, length: 4, hit_count:    55, hit_count %:  0.06, amount:  275000, amount %:  2.95, total amount %:  2.76
symbol: 7, length: 5, hit_count:     4, hit_count %:  0.00, amount:  100000, amount %:  1.07, total amount %:  1.00

symbol: 0,  count: 3, hit_count:  2187, hit_count %: 92.36, amount:  437400, amount %: 67.67, total amount %:  4.38
symbol: 0,  count: 4, hit_count:   174, hit_count %:  7.35, amount:  174000, amount %: 26.92, total amount %:  1.74
symbol: 0,  count: 5, hit_count:     7, hit_count %:  0.30, amount:   35000, amount %:  5.41, total amount %:  0.35
*/
