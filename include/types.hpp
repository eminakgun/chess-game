#ifndef _TYPES_H
#define _TYPES_H

#include <iostream>

namespace chess_core {

    class Piece; // forward declaration
    typedef std::vector<Piece> PieceArray;
    typedef std::vector<PieceArray> BoardArray;

    enum class Color {Black, White};
    enum class Turn : bool {Black = false, White = true};

    // << overloads
    std::ostream& operator<<(std::ostream& lhs, const Turn turn);
    std::ostream& operator<<(std::ostream& lhs, const Color color);

    // Board Row characters
    enum class Rows : int {a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 7};

    // Piece
    enum class PieceTypes {King, Queen, Rook, Knight, Bishop, Pawn, NoPiece};

    struct Position
    {
        Rows x;
        unsigned int y;
    };
    

    }
#endif