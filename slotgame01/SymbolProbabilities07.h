#pragma once

#include <vector>

// Wyprowadzony z 06

namespace SymbolProbabilities07
{
    const std::vector<int>& sp1
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

         65,

        200,
        200,
        200,

        105,
        105,

         75,
    };
/*
    const std::vector<int>& sp4
    {
         50,

        215,

        150,
        150,
        150,

        105,
        105,

         75,
    };
*/
}

/*
all_games: 9000000
won_games: 3090055
hf: 34.33
total_payout_amount: 880107500
bet_amount: 900000000
rtp: 97.79
betline:  1, hit_count: 459698, hit_count %: 5.00
betline:  2, hit_count: 457020, hit_count %: 4.97
betline:  3, hit_count: 463917, hit_count %: 5.04
betline:  4, hit_count: 458638, hit_count %: 4.98
betline:  5, hit_count: 458458, hit_count %: 4.98
betline:  6, hit_count: 461293, hit_count %: 5.01
betline:  7, hit_count: 459252, hit_count %: 4.99
betline:  8, hit_count: 461203, hit_count %: 5.01
betline:  9, hit_count: 457500, hit_count %: 4.97
betline: 10, hit_count: 463143, hit_count %: 5.03
betline: 11, hit_count: 461293, hit_count %: 5.01
betline: 12, hit_count: 461293, hit_count %: 5.01
betline: 13, hit_count: 458458, hit_count %: 4.98
betline: 14, hit_count: 458458, hit_count %: 4.98
betline: 15, hit_count: 457863, hit_count %: 4.98
betline: 16, hit_count: 461803, hit_count %: 5.02
betline: 17, hit_count: 457500, hit_count %: 4.97
betline: 18, hit_count: 463143, hit_count %: 5.03
betline: 19, hit_count: 463917, hit_count %: 5.04
betline: 20, hit_count: 457020, hit_count %: 4.97

symbol: 1, length: 2, hit_count: 5482412, hit_count %:  59.59, amount: 137060300, amount %:  16.66, total amount %:  15.57, cost: 548241200, profit: -411180900
symbol: 1, length: 3, hit_count: 314682, hit_count %:   3.42, amount: 31468200, amount %:   3.82, total amount %:   3.58, cost: 31468200, profit:         0
symbol: 1, length: 4, hit_count:  55516, hit_count %:   0.60, amount: 13879000, amount %:   1.69, total amount %:   1.58, cost:  5551600, profit:   8327400
symbol: 1, length: 5, hit_count:  11739, hit_count %:   0.13, amount: 11739000, amount %:   1.43, total amount %:   1.33, cost:  1173900, profit:  10565100
symbol: 2, length: 3, hit_count: 779793, hit_count %:   8.48, amount: 77979300, amount %:   9.48, total amount %:   8.86, cost: 77979300, profit:         0
symbol: 2, length: 4, hit_count: 125993, hit_count %:   1.37, amount: 31498250, amount %:   3.83, total amount %:   3.58, cost: 12599300, profit:  18898950
symbol: 2, length: 5, hit_count:  24070, hit_count %:   0.26, amount: 24070000, amount %:   2.92, total amount %:   2.73, cost:  2407000, profit:  21663000
symbol: 3, length: 3, hit_count: 797046, hit_count %:   8.66, amount: 79704600, amount %:   9.69, total amount %:   9.06, cost: 79704600, profit:         0
symbol: 3, length: 4, hit_count: 132361, hit_count %:   1.44, amount: 33090250, amount %:   4.02, total amount %:   3.76, cost: 13236100, profit:  19854150
symbol: 3, length: 5, hit_count:  26341, hit_count %:   0.29, amount: 26341000, amount %:   3.20, total amount %:   2.99, cost:  2634100, profit:  23706900
symbol: 4, length: 3, hit_count: 798079, hit_count %:   8.67, amount: 79807900, amount %:   9.70, total amount %:   9.07, cost: 79807900, profit:         0
symbol: 4, length: 4, hit_count: 130926, hit_count %:   1.42, amount: 32731500, amount %:   3.98, total amount %:   3.72, cost: 13092600, profit:  19638900
symbol: 4, length: 5, hit_count:  26218, hit_count %:   0.28, amount: 26218000, amount %:   3.19, total amount %:   2.98, cost:  2621800, profit:  23596200
symbol: 5, length: 3, hit_count: 188822, hit_count %:   2.05, amount: 47205500, amount %:   5.74, total amount %:   5.36, cost: 18882200, profit:  28323300
symbol: 5, length: 4, hit_count:  19759, hit_count %:   0.21, amount: 19759000, amount %:   2.40, total amount %:   2.25, cost:  1975900, profit:  17783100
symbol: 5, length: 5, hit_count:   2298, hit_count %:   0.02, amount:  5745000, amount %:   0.70, total amount %:   0.65, cost:   229800, profit:   5515200
symbol: 6, length: 3, hit_count: 186898, hit_count %:   2.03, amount: 46724500, amount %:   5.68, total amount %:   5.31, cost: 18689800, profit:  28034700
symbol: 6, length: 4, hit_count:  19469, hit_count %:   0.21, amount: 19469000, amount %:   2.37, total amount %:   2.21, cost:  1946900, profit:  17522100
symbol: 6, length: 5, hit_count:   2269, hit_count %:   0.02, amount:  5672500, amount %:   0.69, total amount %:   0.64, cost:   226900, profit:   5445600
symbol: 7, length: 3, hit_count:  70405, hit_count %:   0.77, amount: 35202500, amount %:   4.28, total amount %:   4.00, cost:  7040500, profit:  28162000
symbol: 7, length: 4, hit_count:   5340, hit_count %:   0.06, amount: 26700000, amount %:   3.24, total amount %:   3.03, cost:   534000, profit:  26166000
symbol: 7, length: 5, hit_count:    434, hit_count %:   0.00, amount: 10850000, amount %:   1.32, total amount %:   1.23, cost:    43400, profit:  10806600

symbol: 0,  count: 3, hit_count: 191846, hit_count %:  92.03, amount: 38369200, amount %:  67.09, total amount %:   4.36, cost: 19184600, profit: 19184600
symbol: 0,  count: 4, hit_count:  16053, hit_count %:   7.70, amount: 16053000, amount %:  28.07, total amount %:   1.82, cost: 1605300, profit: 14447700
symbol: 0,  count: 5, hit_count:    554, hit_count %:   0.27, amount: 2770000, amount %:   4.84, total amount %:   0.31, cost:   55400, profit:  2714600
*/
/*
all_games: 9000000
won_games: 3089786
hf: 34.33
total_payout_amount: 879581050
bet_amount: 900000000
rtp: 97.73
betline:  1, hit_count: 460282, hit_count %: 5.01
betline:  2, hit_count: 457549, hit_count %: 4.98
betline:  3, hit_count: 461173, hit_count %: 5.02
betline:  4, hit_count: 458938, hit_count %: 4.99
betline:  5, hit_count: 459525, hit_count %: 5.00
betline:  6, hit_count: 460020, hit_count %: 5.00
betline:  7, hit_count: 459539, hit_count %: 5.00
betline:  8, hit_count: 461948, hit_count %: 5.02
betline:  9, hit_count: 457901, hit_count %: 4.98
betline: 10, hit_count: 461374, hit_count %: 5.02
betline: 11, hit_count: 460020, hit_count %: 5.00
betline: 12, hit_count: 460020, hit_count %: 5.00
betline: 13, hit_count: 459525, hit_count %: 5.00
betline: 14, hit_count: 459525, hit_count %: 5.00
betline: 15, hit_count: 458149, hit_count %: 4.98
betline: 16, hit_count: 461200, hit_count %: 5.02
betline: 17, hit_count: 457901, hit_count %: 4.98
betline: 18, hit_count: 461374, hit_count %: 5.02
betline: 19, hit_count: 461173, hit_count %: 5.02
betline: 20, hit_count: 457549, hit_count %: 4.98

symbol: 1, length: 2, hit_count:   5473402, hit_count %:  59.53, amount: 136835050, amount %:  16.64, total amount %:  15.56, cost: 547340200, profit: -410505150
symbol: 1, length: 3, hit_count:    314128, hit_count %:   3.42, amount:  31412800, amount %:   3.82, total amount %:   3.57, cost:  31412800, profit:          0
symbol: 1, length: 4, hit_count:     55141, hit_count %:   0.60, amount:  13785250, amount %:   1.68, total amount %:   1.57, cost:   5514100, profit:    8271150
symbol: 1, length: 5, hit_count:     11690, hit_count %:   0.13, amount:  11690000, amount %:   1.42, total amount %:   1.33, cost:   1169000, profit:   10521000
symbol: 2, length: 3, hit_count:    780338, hit_count %:   8.49, amount:  78033800, amount %:   9.49, total amount %:   8.87, cost:  78033800, profit:          0
symbol: 2, length: 4, hit_count:    124376, hit_count %:   1.35, amount:  31094000, amount %:   3.78, total amount %:   3.54, cost:  12437600, profit:   18656400
symbol: 2, length: 5, hit_count:     23576, hit_count %:   0.26, amount:  23576000, amount %:   2.87, total amount %:   2.68, cost:   2357600, profit:   21218400
symbol: 3, length: 3, hit_count:    798642, hit_count %:   8.69, amount:  79864200, amount %:   9.71, total amount %:   9.08, cost:  79864200, profit:          0
symbol: 3, length: 4, hit_count:    131754, hit_count %:   1.43, amount:  32938500, amount %:   4.01, total amount %:   3.74, cost:  13175400, profit:   19763100
symbol: 3, length: 5, hit_count:     26224, hit_count %:   0.29, amount:  26224000, amount %:   3.19, total amount %:   2.98, cost:   2622400, profit:   23601600
symbol: 4, length: 3, hit_count:    801206, hit_count %:   8.71, amount:  80120600, amount %:   9.74, total amount %:   9.11, cost:  80120600, profit:          0
symbol: 4, length: 4, hit_count:    132097, hit_count %:   1.44, amount:  33024250, amount %:   4.02, total amount %:   3.75, cost:  13209700, profit:   19814550
symbol: 4, length: 5, hit_count:     26274, hit_count %:   0.29, amount:  26274000, amount %:   3.19, total amount %:   2.99, cost:   2627400, profit:   23646600
symbol: 5, length: 3, hit_count:    187166, hit_count %:   2.04, amount:  46791500, amount %:   5.69, total amount %:   5.32, cost:  18716600, profit:   28074900
symbol: 5, length: 4, hit_count:     19793, hit_count %:   0.22, amount:  19793000, amount %:   2.41, total amount %:   2.25, cost:   1979300, profit:   17813700
symbol: 5, length: 5, hit_count:      2294, hit_count %:   0.02, amount:   5735000, amount %:   0.70, total amount %:   0.65, cost:    229400, profit:    5505600
symbol: 6, length: 3, hit_count:    187964, hit_count %:   2.04, amount:  46991000, amount %:   5.71, total amount %:   5.34, cost:  18796400, profit:   28194600
symbol: 6, length: 4, hit_count:     19948, hit_count %:   0.22, amount:  19948000, amount %:   2.43, total amount %:   2.27, cost:   1994800, profit:   17953200
symbol: 6, length: 5, hit_count:      2214, hit_count %:   0.02, amount:   5535000, amount %:   0.67, total amount %:   0.63, cost:    221400, profit:    5313600
symbol: 7, length: 3, hit_count:     70707, hit_count %:   0.77, amount:  35353500, amount %:   4.30, total amount %:   4.02, cost:   7070700, profit:   28282800
symbol: 7, length: 4, hit_count:      5319, hit_count %:   0.06, amount:  26595000, amount %:   3.23, total amount %:   3.02, cost:    531900, profit:   26063100
symbol: 7, length: 5, hit_count:       432, hit_count %:   0.00, amount:  10800000, amount %:   1.31, total amount %:   1.23, cost:     43200, profit:   10756800

symbol: 0,  count: 3, hit_count:    192008, hit_count %:  92.12, amount:  38401600, amount %:  67.17, total amount %:   4.37, cost:  19200800, profit:   19200800
symbol: 0,  count: 4, hit_count:     15840, hit_count %:   7.60, amount:  15840000, amount %:  27.71, total amount %:   1.80, cost:   1584000, profit:   14256000
symbol: 0,  count: 5, hit_count:       585, hit_count %:   0.28, amount:   2925000, amount %:   5.12, total amount %:   0.33, cost:     58500, profit:    2866500
*/
