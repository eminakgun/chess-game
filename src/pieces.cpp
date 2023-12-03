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

ostream& operator<<(ostream& os, const Piece& piece) {
    os << "Piece type: "  << piece.to_symbol();
    os << ", Piece color: " << piece._color;

    return os;
}

int Piece::score() const {
    int score{0};

    switch (_type)
    {
    case PieceTypes::Queen:
        score = 9;
        break;
    case PieceTypes::Rook:
        score = 5;
        break;
    case PieceTypes::Knight:
    case PieceTypes::Bishop:
        score = 3;
        break;
    case PieceTypes::Pawn:
        score = 1;
        break;
    
    default:
        break;
    }

    return score;
}

PieceTypes Piece::get_type() const {
    return _type;
}
Color Piece::get_color() const {
    return _color;
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

bool Piece::can_move(const Position& src, const Position& dest) const {
    // TODO determine if piece can move to dest
    int diff_y = dest.y - src.y; // better be const

    if (Color::Black == _color && diff_y < 0)
    {
        diff_y = std::abs(diff_y);
    }

    cout << "Piece::can_move : " << *this << endl;
    cout << "Source " << src;
    cout << ", Dest pos:" << dest;
    cout << ", diff_y: " << diff_y << endl;

    if (_type == PieceTypes::Pawn)
    {
        if (src.x != dest.x) // forward only
            return false;
        if (diff_y != 2)
            return false;
        if (diff_y == 2 &&
            (Color::Black == _color && src.y != 7) ||
                (Color::White == _color && src.y != 2))
            return false;
        
        return true;
    }
    else if (_type == PieceTypes::Knight)
    {
        /* code */
    }
    
    
    return true;
}

} // namespace chess_core