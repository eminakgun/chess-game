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
               
        // board 2 single moves
        board.load_from("test/board_2");
        board.play("g2g4", Color::White); // valid


        board.load_from("test/board_2");
        board.play("c4b5", Color::White); // valid

        board.load_from("test/board_2");
        board.play("c4f2", Color::White); // ivalid

        board.load_from("test/board_2");
        board.play("e2e7", Color::White); // valid

        board.load_from("test/board_2");
        board.play("e2f3", Color::White); // ivalid

        board.load_from("test/board_2");
        board.play("a1h1", Color::White); // ivalid

        board.load_from("test/board_2");
        board.play("h1a1", Color::White); // ivalid

        board.load_from("test/board_2");
        board.play("d2f4", Color::White); // valid

        board.load_from("test/board_2");
        board.play("c2c4", Color::White); // ivalid

        board.load_from("test/board_2");
        board.play("f3g5", Color::White); // valid

        board.load_from("test/board_2");
        board.play("a1g1", Color::White); // valid

        exit(1);

        // board 2 game
        board.init();
        board.load_from("test/board_2"); //../
        board.play("c4b5", Color::White);
        board.play("a4b5", Color::Black);
        board.play("e2b5", Color::White);
        board.play("b8c6", Color::Black);
        board.play("d4d5", Color::White);
        board.play("a7a6", Color::Black);
        board.play("b5b7", Color::White);
        board.play("a8b8", Color::Black); // a8b8
        board.play("b7a6", Color::White);
        board.play("c6b4", Color::Black);
        board.play("d2b4", Color::White);
        
        Board temp_board{board};

        board.play("b8b4", Color::Black);
        board.play("h2h3", Color::White);
        board.play("g4c8", Color::Black);
        board.play("a6e2", Color::White);
        board.play("d6c5", Color::Black);
        board.play("f2e1", Color::White);
        board.print();
        board.score_table();
        exit(1); 

        // continue game from temp_board
       chess_core::Game game(temp_board);
       game.set_turn(Color::Black);
       game.play("e8d7");
       game.play("a6c8");
       game.play("h8d8");
       game.play("c8d7");
       game.start();

        exit(1); 
    }
    
    chess_core::Game game(board_path);
    game.start();
}