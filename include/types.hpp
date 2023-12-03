#ifndef _TYPES_H
#define _TYPES_H

#include <iostream>
#include <vector>
using namespace std;
namespace chess_core {

    class Piece; // forward declaration
    typedef vector<Piece> PieceArray;
    typedef vector<PieceArray> BoardArray;

    enum class Color {Black, White};
    enum class Turn : bool {Black = false, White = true};

    // << overloads
    std::ostream& operator<<(std::ostream& lhs, const Turn& turn);
    std::ostream& operator<<(std::ostream& lhs, const Color& color);

    // Board Row characters
    enum class Rows : int {a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 7};
    std::ostream& operator<<(std::ostream& lhs, const Rows& row);

    // Piece
    enum class PieceTypes {King, Queen, Rook, Knight, Bishop, Pawn, NoPiece};

    // Position data type
    struct Position
    {
        unsigned int x;
        unsigned int y;
    };

    Position to_position(const unsigned int column, const unsigned int row);
    void to_position(Position& pos, const unsigned int column, const unsigned int row);
    std::ostream& operator<<(std::ostream& lhs, const Position& pos);

    }
#endif