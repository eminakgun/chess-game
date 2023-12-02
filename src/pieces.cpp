#include <pieces.hpp>

namespace chess_core {

Piece::Piece(PieceTypes type, Color color) : _color(color), _type(type)
{
}

/*
Piece::~Piece()
{
}
*/

int Piece::score() const{
    int score{0};

    return score;
}

string Piece::to_symbol() const {
    string sym;
    switch (_type)
    {
    case PieceTypes::King:
        sym = "K";
        break;
    case PieceTypes::Queen:
        sym = "Q";
        break;
    case PieceTypes::Rook:
        sym = "R";
        break;
    case PieceTypes::Knight:
        sym = "N";
        break;
    case PieceTypes::Bishop:
        sym = "B";
        break;
    case PieceTypes::Pawn:
        sym = "P";
        break;
    case PieceTypes::NoPiece:
        sym = ".";
        break;
    
    default:
        break;
    }

    if (_color == Color::Black)
    {
        sym = tolower(sym[0]);
    }
    

    return sym;
}

Piece Piece::from_symbol(char symbol) {
    switch (symbol) {
        case 'K':
            return Piece(PieceTypes::King, Color::White);
        case 'Q':
            return Piece(PieceTypes::Queen, Color::White);
        case 'R':
            return Piece(PieceTypes::Rook, Color::White);
        case 'N':
            return Piece(PieceTypes::Knight, Color::White);
        case 'B':
            return Piece(PieceTypes::Bishop, Color::White);
        case 'P':
            return Piece(PieceTypes::Pawn, Color::White);
        case 'k':
            return Piece(PieceTypes::King, Color::Black);
        case 'q':
            return Piece(PieceTypes::Queen, Color::Black);
        case 'r':
            return Piece(PieceTypes::Rook, Color::Black);
        case 'n':
            return Piece(PieceTypes::Knight, Color::Black);
        case 'b':
            return Piece(PieceTypes::Bishop, Color::Black);
        case 'p':
            return Piece(PieceTypes::Pawn, Color::Black);
        default:
            return Piece(PieceTypes::NoPiece);
    }
}

} // namespace chess_core