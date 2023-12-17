#pragma once

#include <ostream>

struct LengthBasedPayout
{
    int symbol;
    int length;
    int amount;
    int betline;
};

inline bool operator == (const LengthBasedPayout& p1, const LengthBasedPayout& p2)
{
    return p1.symbol == p2.symbol && p1.length == p2.length && p1.amount == p2.amount && p1.betline == p2.betline;
}

inline std::ostream& operator << (std::ostream& os, const LengthBasedPayout& p)
{
    return os << "{ symbol=" << p.symbol << ", length=" << p.length << ", amount=" << p.amount << ", betline=" << p.betline << " }";
}
