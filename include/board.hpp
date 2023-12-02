#ifndef _BOARD_H
#define _BOARD_H

#include <pieces.hpp>
#include <types.hpp>
#include <fstream>

namespace chess_core {
    class Board
    {
    private:
        std::vector<std::vector<Piece>> _board;
        
    public:
        Board(/* args */);
        Board(const std::string& filename);
        ~Board();

        void print() const;
        bool save_to(const std::string& filename) const;
        bool load_from(const std::string& filename);
        int score(Color color) const;

        void init();
        void play(const string& move);
        bool can_play(const string& move, const Color& current_turn) const;
        bool is_valid_key(const char& key) const;
        bool is_valid_move(const string& move, const Color& current_turn) const;
    };
    
}




#endif