#pragma once

#include <utility>
#include <vector>
//#include <initializer_list>

using payline_pattern = std::vector<std::pair<std::size_t, std::size_t>>;

/*
struct payline_pattern
{
    payline_pattern(const std::string& string_pattern) {}
    payline_pattern(const std::initializer_list<std::pair<int, int>>& coordinates) :
        coordinates{coordinates}
    {
    }

    const std::vector<std::pair<int, int>> coordinates;

    auto begin() const
    {
        return coordinates.begin();
    }

    auto end() const
    {
        return coordinates.end();
    }
};
*/
