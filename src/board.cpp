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

void Board::play(string move) {

}

bool Board::can_play(string move) const {
    return true;

}

} // namespace chess_core