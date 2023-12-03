#include <game.hpp>

namespace chess_core {

Game::Game() : _turn(Turn::White){
    _board.init();
}

Game::Game(Board& board, const std::string& board_path) 
    : _board(board), _turn(Turn::White) {
    if (!board_path.empty())
    {
        _board.load_from(board_path);
    }
    else
        _board.init();
}

Game::~Game()
{
}

void Game::start() {
    cout << "Welcome to the Chess Game!" << endl;

    while(!is_finished()) {
        _board.print();
        get_input();
        if (validate_input())
        {
            _board.play(_move);
            if (_turn == Turn::Black) 
                _turn = Turn::White;
            else
                _turn = Turn::Black;
        }
        else
            get_suggestion();   
    }
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

bool Game::validate_input() const {
    const Color current_color = _turn == Turn::Black ? Color::Black : Color::White;
    
    if (!_board.can_play(_move, current_color)) {
        std::cout << "Invalid input!" << endl; 
        return false;
    }
    return true;
}

void Game::get_suggestion() const {
    string suggestion = "a2a3";
    //TODO Implement
    std::cout << "You can try this move: " << suggestion << endl;
}

bool Game::is_finished() const {
    return false;
}

} // namespace chess_core