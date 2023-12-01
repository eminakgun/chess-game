#ifndef _TYPES_H
#define _TYPES_H

#include <iostream>

enum class Turn : bool {Black = false, White = true};

std::ostream& operator<<(std::ostream& lhs, const Turn turn);

// Board Row characters
enum Rows {a, b, c, d, e, f, g, h};

// Pieces
enum PieceTypes {King, Queen, Rook, Knight, Bishop, Pawn};


#endif