#include <board.hpp>
#include <pieces.hpp>
#include <game.hpp>

using namespace chess_core;

int main(int argc, char *argv[]) {
    bool utest;
    Board board;
    string board_path;

    if (argc == 2) {
        string board_name = argv[1];
        board_path = "test/" + board_name + ".txt";
        utest = static_cast<string>(argv[1]) == "utest";
    }

    if (utest)
    {
        // Knight tests
        Piece knight{PieceTypes::Knight};
        cout << "Knight can move: " << knight.can_move("b8c6") << endl;
        cout << "Knight can move: " << knight.can_move("c6c6") << endl;
        cout << "Knight can move: " << knight.can_move("e1e3") << endl;
        cout << "Knight can move: " << knight.can_move("b6c6") << endl;
        cout << "Knight can move: " << knight.can_move("b6d6") << endl;

        // Rook tests
        Piece rook{PieceTypes::Rook};
        cout << "Rook can move: " << rook.can_move("a2a3") << endl;
        cout << "Rook can move: " << rook.can_move("b8c6") << endl;
        cout << "Rook can move: " << rook.can_move("b8b7") << endl;
        cout << "Rook can move: " << rook.can_move("h3h8") << endl;
        cout << "Rook can move: " << rook.can_move("a5h5") << endl;
        cout << "Rook can move: " << rook.can_move("b8h8") << endl;
        cout << "Rook can move: " << rook.can_move("d4h4") << endl;
        // Fails below
        cout << "Rook can move: " << rook.can_move("b8c6") << endl;
        cout << "Rook can move: " << rook.can_move("b2c3") << endl;
        cout << "Rook can move: " << rook.can_move("d4a6") << endl;
        cout << "Rook can move: " << rook.can_move("d4b6") << endl;

        // Initial board tests
        board.init();
        board.print();
        cout << board.is_valid_move("a2a3", Color::White) << endl;
        cout << board.is_valid_move("a2a4", Color::White) << endl;
        cout << "Pawn e7e5: " << board.is_valid_move("e7e5", Color::Black) << endl;

        // Test pawn takes
        board.init();
        board.play("h2h4", Color::White);
        board.play("g7g5", Color::Black);
        board.play("h4g5", Color::White);
        board.print();
        board.score_table();
        exit(1);        
    }
    
    chess_core::Game game(board, board_path);
    game.start();
}