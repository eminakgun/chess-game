#include <types.hpp>

namespace chess_core {

std::ostream& operator<<(std::ostream& lhs, const Turn& turn) {
    switch (turn){
        case Turn::Black:
            lhs << "Black";
            break;
        case Turn::White:
            lhs << "White";
            break;
        default:
            break;
    }
    return lhs;
}

std::ostream& operator<<(std::ostream& lhs, const Color& color) {
    switch (color){
        case Color::Black:
            lhs << "Black";
            break;
        case Color::White:
            lhs << "White";
            break;
        default:
            break;
    }
    return lhs;
}

std::ostream& operator<<(std::ostream& lhs, const Rows& row) {
    switch (row){
        case Rows::a:
            lhs << "a";
            break;
        case Rows::b:
            lhs << "b";
            break;
        case Rows::c:
            lhs << "c";
            break;
        case Rows::d:
            lhs << "d";
            break;
        case Rows::e:
            lhs << "e";
            break;
        case Rows::f:
            lhs << "f";
            break;
        case Rows::g:
            lhs << "g";
            break;
        case Rows::h:
            lhs << "h";
            break;
        default:
            break;
    }
    return lhs;
}

Position to_position(const unsigned int column, const unsigned int row) {
    return Position{column, row};
}

void to_position(Position& pos, const unsigned int column, const unsigned int row) {
    pos.x = column;
    pos.y = row;
}

std::ostream& operator<<(std::ostream& lhs, const Position& pos) {
    std::cout << "Position: ";
    std::cout << "Row: " << static_cast<Rows>(pos.x);
    std::cout << ", Column: " << pos.y + 1;
    return lhs;
}

} // namespace chess_core