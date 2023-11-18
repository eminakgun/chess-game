#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <string>
#include <types.hpp>
#include <board.hpp>
#include <pieces.hpp>

class Game
{
private:
    Board _board;
    Turn _turn;
    string _move;
    int _score = 0;

    int score() const;
    bool is_finished() const;

public:
    Game(/* args */);
    Game(Board& board);
    ~Game();

    void start();
    void get_input();
    bool validate_input() const;
    string& get_suggestion() const;
};


#endif