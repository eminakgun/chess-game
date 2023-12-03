#include <types.hpp>

namespace chess_core {

std::ostream& operator<<(std::ostream& lhs, const Turn turn) {
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

std::ostream& operator<<(std::ostream& lhs, const Color color) {
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

Position to_position(const unsigned int row, const unsigned int column) {
    return Position{static_cast<Rows>(row), column};
}

void to_position(Position& pos, const unsigned int row, const unsigned int column) {
    pos.x = static_cast<Rows>(row);
    pos.y = column;
}

} // namespace chess_core