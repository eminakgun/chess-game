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


bool Piece::can_move(const string& move) const {
    const Position src_pos = chess_core::to_position(move[0] - 'a', move[1] - '1');
    const Position dest_pos = chess_core::to_position(move[2] - 'a', move[3] - '1');

    return m_can_move(src_pos, dest_pos);
}


bool Piece::can_move(const Position& src, const Position& dest) const {
    return m_can_move(src, dest);
}

bool Piece::m_can_move(const Position& src, const Position& dest) const {
    int diff_x = Color::White == _color ? dest.x - src.x : src.x - dest.x; // better be const
    int diff_y = Color::White == _color ? dest.y - src.y : src.y - dest.y; // better be const
    int abs_diff_x = std::abs(diff_x);
    int abs_diff_y = std::abs(diff_y);

    // cout << "Piece::can_move : " << *this << endl;
    // cout << "Source " << src;
    // cout << ", Dest " << dest;
    // cout << ", diff_x: " << diff_x;
    // cout << ", diff_y: " << diff_y << endl;
    // cout << ", abs_diff_x: " << abs_diff_x;
    // cout << ", abs_diff_y: " << abs_diff_y << endl;

    // return if source and destination is the same
    if (src == dest)
        return false;

    if (_type == PieceTypes::Pawn)
    {
        if (src.x != dest.x) {
            cout << "Pawn can only move in the same column!" << endl;
            return false;
        }
        if (diff_y == 0)
            return false;
        if (diff_y == 2 &&
              ((Color::Black == _color && src.y != 6) ||
                (Color::White == _color && src.y != 1)))
                return false;
        if (diff_y > 2)
                return false;
        
        return true;
    }
    else if (_type == PieceTypes::Knight)
    {
        if (abs_diff_y != 1 && abs_diff_y != 2)
            return false;
        if (abs_diff_x != 1 && abs_diff_x != 2)
            return false;
        if (abs_diff_x + abs_diff_y != 3)
            return false;
        return true;
    }
    else if (_type == PieceTypes::Bishop) {
        if (abs_diff_x != abs_diff_y)
            return false;
    }
    else if (_type == PieceTypes::Rook) {
        if (abs_diff_y != 0 && abs_diff_x != 0)
            return false;
    }
    else if (_type == PieceTypes::King) {
        if (abs_diff_y + abs_diff_x > 2)
            return false;
    }
    else if (_type == PieceTypes::Queen) {
        // there's no invalid moves for queen
    }

    return true;
}

} // namespace chess_core