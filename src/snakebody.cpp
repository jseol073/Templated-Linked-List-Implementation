#include "snakebody.h"

namespace snakelinkedlist {

std::ostream& operator<<(std::ostream& os, const SnakeBodySegment& list) {
    os << list.data_;
    return os;
}

bool operator==(const SnakeBodySegment& lhs, const SnakeBodySegment& rhs) {
    return (lhs.data_ == rhs.data_);
}

bool operator!=(const SnakeBodySegment& lhs, const SnakeBodySegment& rhs) {
    return !(lhs == rhs);
}

SnakeBodySegment operator+(const SnakeBodySegment& lhs, const SnakeBodySegment& rhs) {
    return(SnakeBodySegment(lhs.data_ + rhs.data_));    
}

SnakeBodySegment operator+(const SnakeBodySegment& lhs, const SnakeBodySegment& rhs) {
    return(SnakeBodySegment(lhs.data_ + rhs.data_));    
}

} // namespace snakelinkedlist