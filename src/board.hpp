#ifndef _BOARD_H
#define _BOARD_H

#include <pieces.hpp>
#include <types.hpp>

class Board
{
private:
    Pieces _black;
    Pieces _white;
    
public:
    Board(/* args */);
    ~Board();

    void print() const;
    int score() const;

    void play(string move);
    bool can_play(string move) const;
};




#endif