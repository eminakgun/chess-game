#include <game.hpp>

namespace chess_core {

Game::Game() {
    _board.init();
}

Game::Game(Board& board, const std::string& board_path) : _board(board){
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
    _board.print();

    while(!is_finished()) {
        get_input();
        if (validate_input())
        {
            _board.play(_move);
        }
        else
            _board.play(get_suggestion());
        
        if (_turn == Turn::Black) 
            _turn = Turn::White;
        else
            _turn = Turn::Black;
    }
}

void Game::get_input() {
    cout << "[" << _turn;
    cout << "'s Turn]" << endl;
    cout << "Enter your move:" << endl;
    cin >> _move;
}
bool Game::validate_input() const {
    if ("exit" == _move)
    {
        _board.save_to("board.txt");
        std::exit(0);
    }
    
    return _board.can_play(_move);
}
string& Game::get_suggestion() const {
    string suggestion;

    return suggestion;
}

bool Game::is_finished() const {
    return false;
}

} // namespace chess_core