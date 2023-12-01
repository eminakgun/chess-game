#include <types.hpp>

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