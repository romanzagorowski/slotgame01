#include "SlotGameSimulator.h"
#include "BetLines.h"
#include "CountBasedPrizes.h"
#include "LengthBasedPrizes.h"

#include "RandomSymbolsGenerator.h"
#include "FixedProbabilitySymbolsGenerator.h"
#include "FixedProbabilitySymbolGenerator.h"
#include "ColumnSymbolsGenerator.h"
#include "GameSymbolsGeneratorCSG1.h"
#include "GameSymbolsGeneratorCSG5.h"

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

void f1()
{

    SlotGameSimulator simulator{
        5, 3,
        betlines,
        length_based_prizes,
        count_based_prizes
    };

    RandomSymbolsGenerator generator{ 5, 3 };

    simulator.Run(
        10000,
        generator
    );
}

void f2()
{
    FixedProbabilitySymbolsGenerator generator{ 5, 3 };

    for(int i = 0; i < 10; ++i)
        std::cout << generator.Generate() << std::endl;

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
            10,
            30,
            10,
            10,
            10,
            10,
            10,
            10
        },
    };

    FixedProbabilitySymbolGenerator sg2{
        {
            10,
            30,
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
            10,
            30,
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
            10,
            30,
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
            10,
            30,
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

    GameSymbolsGeneratorCSG5 gsg{ 5, 3, 
        {&cg1, &cg2, &cg3, &cg4, &cg5 }
    };

    simulator.Run(
        100000,
        gsg
    );
}

int main()
{
    f3();
}
