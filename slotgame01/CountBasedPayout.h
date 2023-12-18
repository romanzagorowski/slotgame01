#pragma once

#include <ostream>

struct CountBasedPayout
{
    int symbol;
    int count;
    int amount;
};

inline bool operator == (const CountBasedPayout& p1, const CountBasedPayout& p2)
{
    return p1.symbol == p2.symbol && p1.count == p2.count && p1.amount == p2.amount;
}

inline std::ostream& operator << (std::ostream& os, const CountBasedPayout& p)
{
    return os << "{ symbol=" << p.symbol << ", count=" << p.count << ", amount=" << p.amount << " }";
}
