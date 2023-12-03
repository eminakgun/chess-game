#include <board.hpp>

namespace chess_core {

Board::Board(/* args */)
{
}

Board::~Board()
{
}

void Board::init() {
    _board.resize(8, std::vector<Piece>(8));

    for (int i = 0; i < 8; ++i) {
        Color color = (i == 0 && i == 1) ? Color::White : Color::Black;
        for (int j = 0; j < 8; ++j) {
            if (i == 1) {
                // White Pawn
                _board[i][j] = Piece(PieceTypes::Pawn, Color::White);
            } else if (i == 6) {
                // Black Pawn
                _board[i][j] = Piece(PieceTypes::Pawn, Color::Black);
            } else if (i == 0 || i == 7) {
                PieceTypes type = PieceTypes::NoPiece;
                switch (j){
                    case 0:
                    case 7:
                        type = PieceTypes::Rook;
                        break;
                    
                    case 1:
                    case 6:
                        type = PieceTypes::Knight;
                        break;

                    case 2:
                    case 5:
                        type = PieceTypes::Bishop;
                        break;

                    case 3:
                        type = PieceTypes::Queen;
                        break;

                    case 4:
                        type = PieceTypes::King;
                        break;
                    
                    default:
                        break;
                }
                
                _board[i][j] = Piece(type, (i == 0) ? Color::White : Color::Black);
            }
            else
                _board[i][j] = Piece(PieceTypes::NoPiece);
        }
    }

}


const Piece& Board::at(const Position& pos) const {
    return _board.at(pos.y).at(pos.x);
}

void Board::print() const {

    for (int i = 7; i >= 0; --i) {
        std::cout << i + 1 << " | ";
        for (int j = 0; j < 8; ++j) {
            std::cout << _board[i][j].to_symbol() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-----------------------" << std::endl;
    std::cout << "    a b c d e f g h" << std::endl;
}

bool Board::save_to(const std::string& filename) const {
    std::ofstream file(filename + ".txt");
    if (file.is_open()) {
        for (int i = 7; i >= 0; --i) {
            for (int j = 0; j < 8; ++j) {
                file << _board[i][j].to_symbol();
            }
            file << std::endl;
        }
        file.close();
        std::cout << "Board saved to " << filename << std::endl;
        return true;
    }
    return false;
}

bool Board::load_from(const std::string& filename) {
    std::ifstream file(filename + ".txt");
    if (file.is_open()) {
        std::cout << "Trying to load board from: " << filename << endl;
        _board.resize(8, std::vector<Piece>(8));
        for (int i = 7; i >= 0; --i) {
            for (int j = 0; j < 8; ++j) {
                char symbol;
                file >> symbol;
                //std::cout << "j'th symbol: " << symbol << endl;
                _board[i][j] = Piece::from_symbol(symbol);
            }
        }
        file.close();
        std::cout << "Board loaded from " << filename << ",\n"<< std::endl;
        print();
        return true;
    }
    return false;
}

void Board::score_table() const {
    int white = score(Color::White);
    int black = score(Color::Black);

    std::cout << "White score: " << white << endl;
    std::cout << "Black score: " << black << endl;
}

int Board::score(Color color) const {
    int score{0};

    for (const auto& row : _board)
        for (const auto& element : row)
            if (element.get_color() == color) {
                score += element.score();
                if (is_under_attack(element)) {
                    score -= element.score() / 2;
                }
            }
    return score;
}

void Board::play(const string& move) {
    const unsigned int start_index = move[0] - 'a';
    const unsigned int start_num   = move[1] - '1';
    const unsigned int end_index   = move[2] - 'a';
    const unsigned int end_num     = move[3] - '1';

    src_pos = chess_core::to_position(start_index, start_num);
    dest_pos = chess_core::to_position(end_index, end_num);

    _board[end_num][end_index] = find_piece(src_pos);
    _board[start_num][start_index] = Piece(PieceTypes::NoPiece);
}

bool Board::can_play(const string& move, const Color& current_turn) const {

    if (move.size() != 4)
        return false;

    // validate each character
    for (char c : move)
        if (!is_valid_key(c))
            return false;

    // validate requested move        
    if (!is_valid_move(move, current_turn))
        return false;
    
    return true;

}

bool Board::is_valid_key(const char& key) const {
    static const std::vector<char> valid_chars = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    static const std::vector<char> valid_nums = {'1', '2', '3', '4', '5', '6', '7', '8'};
    std::vector<char> to_search;

    if (std::isalpha(key))
        to_search = valid_chars;
    else
        to_search = valid_nums;

    for (char c : to_search)
        if (c == key)
            return true;

    //cout << "Key is not valid" << endl;;
    return false;
}

bool Board::is_valid_move(const string& move, const Color& current_turn) const {
    const unsigned int start_index = move[0] - 'a';
    const unsigned int start_num   = move[1] - '1';
    const unsigned int end_index   = move[2] - 'a';
    const unsigned int end_num     = move[3] - '1';

    const Position src_pos = chess_core::to_position(start_index, start_num);
    const Position dest_pos = chess_core::to_position(end_index, end_num);

    const Piece& src_piece  = _board[start_num][start_index];
    const Piece& dest_piece = _board[end_num][end_index];

    cout << "Src, " << src_piece << endl;
    cout << "Dest, " << dest_piece << endl;

    // Can't move if current player does not exist in source
    if (src_piece.get_type() == PieceTypes::NoPiece ||
            src_piece.get_color() != current_turn) {
            cout << "Can't move if current player does not exist in source!" << endl;
            return false;
    }
    // Can't move if current player's piece exists in destination
    else if (dest_piece.get_type() != PieceTypes::NoPiece &&
                dest_piece.get_color() == current_turn) {
        cout << "Can't move if current player's piece exists in destination" << endl;
        return false;
    }
    else if (is_under_attack(PieceTypes::King, current_turn)){
        // if King is under attack
        if (src_piece.get_type() != PieceTypes::King)
        {
            return true;
        }
        else
            return false;
        
        // TODO
        // check if source piece can protect the king or can take destination piece
    }

    // Check if source piece can move to destination
    if (src_piece.can_move(src_pos, dest_pos)) {
        cout << "Can move!" << endl;
        if (!is_path_free(src_piece.get_type(), src_pos, dest_pos))
            return false;
    }
    else // can't move
        if (src_piece.get_type() == PieceTypes::Pawn &&
                !can_take(src_piece, dest_piece))
            return false;
        else
            return false;
    
    return true;
}

bool Board::is_under_attack(const PieceTypes type, const Color& color) const {
    return m_is_under_attack(find_position(find_piece(type, color)));
}

bool Board::is_under_attack(const Piece& piece) const {
    return m_is_under_attack(find_position(piece));
}

bool Board::is_under_attack(const Position& dest) const {
    return m_is_under_attack(dest);
}


bool Board::m_is_under_attack(const Position& dest) const {
    Piece piece = at(dest);
    for (const auto& row : _board)
        for (const auto& element : row)
                if (can_take(element, piece))
                    return true;
    return false;
}


bool Board::is_path_free(const PieceTypes type, const Position& src, const Position& dest) const {
    if (type != PieceTypes::Knight && type != PieceTypes::King && type != PieceTypes::Pawn)
    {
        const int diff_x = dest.x - src.x;
        const int diff_y = dest.y - src.y;
        const unsigned int x_incr = (diff_x != 0) ? (diff_x > 0 ? 1 : -1) : 0;
        const unsigned int y_incr = (diff_y != 0) ? (diff_y > 0 ? 1 : -1) : 0;
        unsigned int x_delta = x_incr;
        unsigned int y_delta = y_incr;

        for (int i = 0; i < max(abs(diff_x), abs(diff_y)); i++)
        {
            Position projected = Position{src.x+ x_delta, src.y + y_delta};
            cout << "Check position " << projected << endl;
            if (at(projected).get_type() != PieceTypes::NoPiece) {
                cout << "Found piece at " << projected << endl;
                return false;
            }
            x_delta += x_incr;
            y_delta += y_incr;
        }
    }

    return true;
}

bool Board::can_take(const Piece& src, const Piece& dest) const {
    const Position src_pos = find_position(src);
    const Position dest_pos = find_position(dest);
    const int diff_x = dest_pos.x - src_pos.x;
    const int diff_y = dest_pos.y - src_pos.y;

    // Rule for Pawn       
    if (dest.get_type() != PieceTypes::NoPiece) {
        if (src.get_type() == PieceTypes::Pawn)
            if (!(std::abs(diff_x) == 1 && std::abs(diff_x) == 1))
                return false;
    }
    
    return true;
}

const Piece& Board::find_piece(const Position pos) const {
    return at(pos);
}

const Piece& Board::find_piece(const PieceTypes type, const Color& color) const {
    return m_find_piece(type, color);
}

const Piece& Board::m_find_piece(const PieceTypes type, const Color& color) const {
    for (const auto& row : _board)
        for (const auto& element : row)
            if (element.get_type() == type && element.get_color() == color)
                return element;
    return no_piece;
}

const Position Board::find_position(const Piece& piece) const {
    Position pos;
    auto type = piece.get_type();
    auto color = piece.get_color();
    for (int i = 0; i < 8; ++i) // rows
        for (int j = 0; j < 8; ++j) { // column
            const auto& element = _board[i][j];
            if (element.get_type() == type && element.get_color() == color) {
                pos.x = j;
                pos.y = i;
                return pos;
            }
        }
    return pos;
}


} // namespace chess_core