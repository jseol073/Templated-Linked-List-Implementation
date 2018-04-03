#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "./catch.hpp"
#include "../src/ll.h"
#include "../src/snakebody.h"

TEST_CASE("test default constructor") {
    std::vector<snakelinkedlist::SnakeBodySegment> test;
    test.push_back(5);
    snakelinkedlist::LinkedList expected;
    snakelinkedlist::Node* list_head = nullptr;
    REQUIRE(nullptr == nullptr);
}

TEST_CASE("test move constructor") {
    std::vector<snakelinkedlist::SnakeBodySegment> test;
    test.push_back(5);
    snakelinkedlist::LinkedList expected;
    snakelinkedlist::Node* list_head = nullptr;
    REQUIRE(nullptr == list_head);
}
