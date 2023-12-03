#ifndef _PIECES_H
#define _PIECES_H

#include <cctype>
#include <types.hpp>
namespace chess_core {

    class Piece {
    private:
        Color _color;
        PieceTypes _type;
        bool _status;

        // Functions
        bool m_can_move(const Position& src, const Position& dest) const;

    public:
        explicit Piece(PieceTypes type=PieceTypes::Pawn, Color color=Color::White);
        //~Piece();

        friend ostream& operator<<(ostream& os, const Piece& piece);

        PieceTypes get_type() const;
        Color get_color() const;
        bool is_alive() const;
        int score() const;
        string to_symbol() const;
        static Piece from_symbol(char symbol);

        bool can_move(const string& move) const;
        bool can_move(const Position& src, const Position& dest) const;
    };
}

#endif