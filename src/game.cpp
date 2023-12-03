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
}

void Game::get_suggestion() const {
    string suggestion = "a2a3";
    //TODO Implement suggestion algorithm, i.e best move function
    std::cout << "You can try this move: " << suggestion << endl;
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