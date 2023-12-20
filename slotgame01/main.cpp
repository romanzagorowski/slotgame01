#include "SlotGameSimulator.h"
#include "BetLines.h"
#include "CountBasedPrizes.h"
#include "LengthBasedPrizes.h"

#include "FixedProbabilitySymbolGenerator.h"
#include "ColumnSymbolsGenerator.h"
#include "GameSymbolsGenerator_CSG1.h"
#include "GameSymbolsGenerator_CSG5.h"
#include "GameSymbolsGenerator_Random.h"

#include "SymbolProbabilities07.h"
using namespace SymbolProbabilities07;

#include <vector>
#include <iostream>

inline std::ostream& operator << (std::ostream& os, const std::vector<int>& v)
{
    assert(15 == v.size());

    for(std::size_t r = 0; r < 3; ++r)
    {
        for(std::size_t c = 0; c < 5; ++c)
        {
            os << v[r * 5 + c];
        }
        os << std::endl;
    }

    return os;

    //os << "{ ";

    //std::string sep = "";

    //for(const auto& i : v)
    //{
    //    os << sep;

    //    if(sep == "")
    //        sep = ", ";

    //    os << i;
    //}

    //return os << " }";
}

void f3()
{
    SlotGameSimulator simulator{
        5, 3,
        betlines,
        length_based_prizes,
        count_based_prizes
    };

    FixedProbabilitySymbolGenerator sg1{
        {
             1,

            36,
            11,
            11,
            11,
            
            10,
            10,
            
            10
        },
    };

    FixedProbabilitySymbolGenerator sg2{
        {
             5,

            35,
            10,
            10,
            10,
            10,
            10,
            10
        },
    };

    FixedProbabilitySymbolGenerator sg3{
        {
             5,
            35,
            10,
            10,
            10,
            10,
            10,
            10
        },
    };

    FixedProbabilitySymbolGenerator sg4{
        {
             5,
            35,
            10,
            10,
            10,
            10,
            10,
            10
        },
    };

    FixedProbabilitySymbolGenerator sg5{
        {
             5,
            35,
            10,
            10,
            10,
            10,
            10,
            10
        },
    };

    ColumnSymbolsGenerator cg1{ 3, sg1 };
    ColumnSymbolsGenerator cg2{ 3, sg2 };
    ColumnSymbolsGenerator cg3{ 3, sg3 };
    ColumnSymbolsGenerator cg4{ 3, sg4 };
    ColumnSymbolsGenerator cg5{ 3, sg5 };

    GameSymbolsGenerator_CSG5 gsg{ 5, 3, 
        {&cg1, &cg2, &cg3, &cg4, &cg5 }
    };

    simulator.Run(
        100000,
        gsg
    );
}

void f4()
{
    SlotGameSimulator simulator{
        5, 3,
        betlines,
        length_based_prizes,
        count_based_prizes
    };

    GameSymbolsGenerator_Random gsg{ 5, 3, 8 };

    simulator.Run(
        100000,
        gsg
    );
}

void f5()
{
    SlotGameSimulator simulator{
        5, 3,
        betlines,
        length_based_prizes,
        count_based_prizes
    };

    FixedProbabilitySymbolGenerator sg1{
        sp1
    };

    FixedProbabilitySymbolGenerator sg2{
        sp2
    };

    FixedProbabilitySymbolGenerator sg3{
        sp3
    };

    FixedProbabilitySymbolGenerator sg4{
        sp4
    };

    FixedProbabilitySymbolGenerator sg5{
        sp5
    };

    ColumnSymbolsGenerator cg1{ 3, sg1 };
    ColumnSymbolsGenerator cg2{ 3, sg2 };
    ColumnSymbolsGenerator cg3{ 3, sg3 };
    ColumnSymbolsGenerator cg4{ 3, sg4 };
    ColumnSymbolsGenerator cg5{ 3, sg5 };

    GameSymbolsGenerator_CSG5 gsg{ 5, 3,
        {&cg1, &cg2, &cg3, &cg4, &cg5 }
    };

    simulator.Run(
        9999999,
        gsg
    );
}

int main()
{
    f5();
}
