#include <game.hpp>

namespace chess_core {

Game::Game() : _turn(Color::White) {
    _board.init();
}

Game::Game(const std::string& board_path) 
    : _turn(Color::White) {
    if (!board_path.empty()) {
        _board.load_from(board_path);
    }
}

Game::Game(Board& board) : _board(board), _turn(Color::White) {
}

Game::~Game()
{
    // there's no dynamically alocated objects
}

void Game::set_turn(Color turn) {
    _turn = turn;
}

void Game::start() {
    cout << "Welcome to the Chess Game!" << endl;

    while(!is_finished()) {
        _board.print();
        get_input();
        play();
    }

    cout << "Game is Over!" << endl;
    _board.score_table();
}

void Game::play() {
    m_play();
}

void Game::play(const string& move) {
    _move = move;
    m_play();
}

void Game::m_play() {
    if (_board.play(_move, _turn)) {
        if (_turn == Color::Black) 
            _turn = Color::White;
        else
            _turn = Color::Black;
    }
    else
        get_suggestion();
}

void Game::get_input() {
    cout << "[" << _turn;
    cout << "'s Turn]" << endl;
    cout << "Enter your move:" << endl;
    cin >> _move;

    if ("exit" == _move) {
        std::exit(0);
    } 
    else if ("load" == _move) {
        std::string filename;
        std::cout << "Enter filename to load: ";
        std::cin >> filename;
        _board.load_from(filename);
        get_input();
    }
    else if ("save" == _move) {
        std::string filename;
        std::cout << "Enter filename to save: ";
        std::cin >> filename;
        _board.save_to(filename);
        get_input();
    }
    else if ("suggest" == _move) {
        get_suggestion();
    }
    else if ("score" == _move) {
        _board.score_table();
        get_input();
    }
}

void Game::get_suggestion() const {
    string suggestion = "a2a3";
    //TODO Implement suggestion algorithm, i.e best move function

    int best_score = 0;
    suggestion = minimax(_board, 10, _turn, best_score); // 10 move depth


    std::cout << "You can try this move: " << suggestion << endl;
}

string Game::minimax(const Board& board, int depth, Color& color, int& best_score) {

    // For white part
    // TODO add black part
    string best_move = "";
    int max_score = 0;
    for (const auto& move: board.get_possible_moves(color)) {
        Board new_board{board}; // TODO allocate new board
        new_board.play(move, color);
        int unsigned score = new_board.score(color);
        if (score > max_score)
        {
            best_move = move;
            max_score = score;
        }
    }
    
    if (depth == 0)
        return best_move;
    
    best_score = max_score > best_score ? max_score : best_score;
    color = Color::Black;
    Board next_board{board}; // TODO allocate new board
    next_board.play(best_move, color);
    
    return minimax(next_board, --depth, color, best_score);
}

bool Game::is_finished() const {
    // check if any of the Kings are taken
    Piece white_k = _board.find_piece(PieceTypes::King, Color::White);
    Piece black_k = _board.find_piece(PieceTypes::King, Color::Black);

    // cout << white_k << endl;
    // cout << black_k << endl;

    if (white_k.get_type() == PieceTypes::NoPiece ||
         black_k.get_type() == PieceTypes::NoPiece)
        return true;
    
    return false;
}

} // namespace chess_core