#pragma once

#include "GameBoard.h"

#include <vector>

// Represents a bet line.
// The vector of pairs of ints defines points on the game board that belongs to the bet line.
// The id is for identification purpose. The same as numbers in the online game info screen.

class BetLine
{
public:
    BetLine(int id, const std::vector<std::pair<int, int>>& points) :
        id{ id },
        points{ points }
    {
    }

public:
    auto GetId() const -> int { return this->id; }
    auto GetSymbols(const GameBoard& board) const -> std::vector<int>
    {
        std::vector<int> symbols;

        for(auto& [col, row] : points)
        {
            symbols.push_back(
                board.GetSymbolAt(col, row)
            );
        }

        return symbols;
    }

private:
    const int id;
    const std::vector<std::pair<int, int>> points;
};
