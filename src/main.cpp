#include <board.hpp>
#include <pieces.hpp>
#include <game.hpp>

using namespace chess_core;

int main(int argc, char *argv[]) {
    Board board;
    string board_path;

    board.init();
    board.print();
    cout << board.is_valid_move("a2a3", Color::White) << endl;
    exit(1);

    if (argc == 2) {
        string board_name = argv[1];
        board_path = "test/" + board_name + ".txt";
    }
    
    chess_core::Game game(board, board_path);
    game.start();
}