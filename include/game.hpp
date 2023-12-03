#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include <string>
#include <types.hpp>
#include <board.hpp>
#include <pieces.hpp>
#include <types.hpp>

namespace chess_core {

    class Game {
    private:
        Board _board;
        Color _turn;
        string _move;
        int _score = 0;

        void m_play();
        

    public:
        Game();
        Game(Board& board);
        Game(const std::string& board_path);
        ~Game();

        void set_turn(Color turn);

        void start();
        void play();
        void play(const string& move);
        void get_input();
        bool validate_input() const;
        void get_suggestion() const;

        int score() const;
        bool is_finished() const;
    };
}

#endif