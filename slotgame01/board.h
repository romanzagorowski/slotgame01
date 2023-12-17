#pragma once

#include <cassert>
#include <cstddef>
#include <ostream>

template <std::size_t Reels, std::size_t Rows>
struct board
{
    int v[Reels * Rows]{};

    int at(std::size_t reel, std::size_t row) const
    {
        assert(reel < Reels);
        assert(row < Rows);

        return v[row * Reels + reel];
    }
};

using board_5_3 = board<5, 3>;

template <std::size_t Reels, std::size_t Rows>
std::ostream& operator << (std::ostream& os, const board<Reels, Rows>& b)
{
    for(std::size_t row = 0; row < Rows; ++row)
        for(std::size_t reel = 0; reel < Reels; ++reel)
            os << b.at(reel, row) << (reel + 1 == Reels ? '\n' : ' ');

    return os;
}
