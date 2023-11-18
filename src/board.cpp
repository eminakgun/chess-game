#include <board.hpp>

Board::Board(/* args */)
{
}

Board::~Board()
{
}

// print board
void Board::print() const {

}


int Board::score() const{
    int score{0};

    cout << "Black's score: " << _black.score(); 
    cout << "White's score: " << _white.score();

    return _black.score() + _white.score();
}