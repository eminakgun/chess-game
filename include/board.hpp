#ifndef _BOARD_H
#define _BOARD_H

#include <fstream>
#include <pieces.hpp>
#include <types.hpp>
#include <globals.hpp>

namespace chess_core {
    class Board
    {
    private:
        
        BoardArray _board;
        Piece no_piece{PieceTypes::NoPiece};

        // Functions
        bool m_is_under_attack(const Position& dest) const;
        const Piece& m_find_piece(const PieceTypes type, const Color& color) const;

    public:

        Position src_pos;
        Position dest_pos;

        // Big Three
        Board(/* args */);
        Board(const std::string& filename);
        //Board(const Board board);
        ~Board();

        // Status Interface
        const Piece& at(const Position& dest) const;

        void print() const;
        void score_table() const;
        int score(Color color) const;
        bool save_to(const std::string& filename) const;
        bool load_from(const std::string& filename);

        void init();
        void play(const string& move);
        
        // Query Interface
        bool can_play(const string& move, const Color& current_turn) const;
        bool is_valid_key(const char& key) const;
        bool is_valid_move(const string& move, const Color& current_turn) const;

        bool can_take(const Piece& src, const Piece& dest) const;
        bool is_path_free(const PieceTypes type, const Position& src, const Position& dest) const;
        
        // is_under_attack overloads
        bool is_under_attack(const PieceTypes type, const Color& color) const;
        bool is_under_attack(const Position& pos) const;
        bool is_under_attack(const Piece& piece) const;
        
        // find_peace overloads
        const Piece& find_piece(const PieceTypes type, const Color& color) const;
        const Piece& find_piece(const Position pos) const;
        
        const Position find_position(const Piece& piece) const;
    };
    
}




#endif