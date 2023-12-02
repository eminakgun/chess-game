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

// print board
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
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 7; i >= 0; --i) {
            for (int j = 0; j < 8; ++j) {
                file << _board[i][j].to_symbol();
            }
            file << std::endl;
        }
        file.close();
        std::cout << "Board saved to " << filename << std::endl;
    }
}

bool Board::load_from(const std::string& filename) {
    std::ifstream file(filename);
    _board.resize(8, std::vector<Piece>(8));
    
    std::cout << "Trying to load board from: " << filename << endl;
    if (file.is_open()) {
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
    }
}

int Board::score(Color color) const {
    int score{0};


    return score;
}

void Board::play(const string& move) {

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
    return false;
}

bool Board::is_valid_move(const string& move, const Color& current_turn) const {
    const int start_index = move[0] - 'a';
    const int start_num   = move[1] - '1';
    const int end_index   = move[2] - 'a';
    const int end_num     = move[3] - '1';

    const Piece& source = _board[start_index][start_num];
    const Piece& dest   = _board[end_index][end_num];

    // Can't move if current player does not exist in source
    if (source.get_type() == PieceTypes::NoPiece ||
            source.get_color() != current_turn)
        return false;

    // Can't move if current player's piece exists in destination
    else if (dest.get_type() != PieceTypes::NoPiece &&
                dest.get_color() == current_turn)
        return false;

    // TODO
    // Check if King is under attack
        // Check if King is the source piece
        // else Error

    // Check if source piece can move to destination
        // Check if any piece exists through travel path
        // else Error
    // else Error
        
    return true;
}

} // namespace chess_core