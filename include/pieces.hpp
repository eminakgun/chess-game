#ifndef _PIECES_H
#define _PIECES_H

#include <vector>
#include <types.hpp>
using namespace std;

class Pieces
{
private:
    std::vector<PieceTypes> _pieces;

public:
    Pieces(/* args */);
    ~Pieces();

    int score() const;
};

#endif