#include "SlotGameSimulator.h"
#include "BetLines.h"
#include "CountBasedPrizes.h"
#include "LengthBasedPrizes.h"

#include "RandomSymbolsGenerator.h"

#include <vector>
#include <iostream>

int main2()
{
    const std::vector symbols{ 0,1,2,3,4,5,5,5,5,5,6,6,6,6,6 };

    SlotGameSimulator simulator{
        5, 3, 
        betlines, 
        length_based_prizes,
        count_based_prizes
    };

    simulator.Spin(symbols);

    return 0;
}

std::ostream& operator << (std::ostream& os, const std::vector<int>& v)
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

int main()
{
    RandomSymbolsGenerator generator{ 5, 3 };

    for(int i = 0; i < 10; ++i)
    std::cout << generator.Generate() << std::endl;
}
