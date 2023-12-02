#ifndef _PIECES_H
#define _PIECES_H

#include <vector>
#include <types.hpp>
#include <cctype>
using namespace std;

namespace chess_core {

    class Piece {
    private:
        Color _color;
        PieceTypes _type;

    public:
        explicit Piece(PieceTypes type=PieceTypes::Pawn, Color color=Color::White);
        //~Piece();

        PieceTypes get_type() const;
        Color get_color() const;

        int score() const;
        string to_symbol() const;
        static Piece from_symbol(char symbol);
    };
}

#endif