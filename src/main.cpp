#include <board.hpp>
#include <pieces.hpp>
#include <game.hpp>

int main() {

    Board board;
    Game game(board);

    game.start();
}