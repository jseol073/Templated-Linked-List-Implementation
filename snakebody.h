#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <vector>

namespace snakelinkedlist {

// Internal List Nodes
struct SnakeBodySegment {
    int data_;
    SnakeBodySegment() : data_(0) {};
    SnakeBodySegment(const int v) : data_(v) {};
};

std::ostream& operator<<(std::ostream& os, const SnakeBodySegment& list);
bool operator==(const SnakeBodySegment& lhs, const SnakeBodySegment& rhs);
bool operator!=(const SnakeBodySegment& lhs, const SnakeBodySegment& rhs);
SnakeBodySegment operator+(const SnakeBodySegment& lhs, const SnakeBodySegment&);

} // namespace snakelinkedlist
#endif //SNAKE_H