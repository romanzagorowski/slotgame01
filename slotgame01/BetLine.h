#pragma once

#include "GameBoard.h"

#include <vector>

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
    int id;
    const std::vector<std::pair<int, int>> points;
};
