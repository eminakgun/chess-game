#include <board.hpp>
#include <pieces.hpp>
#include <game.hpp>

int main(int argc, char *argv[]) {
    chess_core::Board board;
    string board_path;

    if (argc == 2) {
        string board_name = argv[1];
        board_path = "test/" + board_name + ".txt";
    }
    
    chess_core::Game game(board, board_path);
    game.start();
}