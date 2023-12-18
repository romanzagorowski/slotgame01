#include "SlotGameSimulator.h"
#include "BetLines.h"
#include "CountBasedPrizes.h"
#include "LengthBasedPrizes.h"

#include "RandomSymbolsGenerator.h"
#include "FixedProbabilitySymbolsGenerator.h"
#include "FixedProbabilitySymbolGenerator.h"

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
    const std::vector symbols{ 0,1,2,3,4,5,5,5,5,5,6,6,6,6,6 };

    SlotGameSimulator simulator{
        5, 3,
        betlines,
        length_based_prizes,
        count_based_prizes
    };

    //FixedProbabilitySymbolsGenerator generator;
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

int main()
{
    f1();
}
