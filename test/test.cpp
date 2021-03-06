#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "./catch.hpp"
#include "../src/ll.h"
#include "../src/snakebody.h"

TEST_CASE("test default constructor") {
    snakelinkedlist::LinkedList actual = snakelinkedlist::LinkedList();
    REQUIRE(actual.size() == 0);
}

TEST_CASE("explicit constructor test") {
    std::vector<snakelinkedlist::SnakeBodySegment> test_values;
    int vector_length = 5;
    for (int i = 0; i < vector_length; i++) {
        test_values.push_back(snakelinkedlist::SnakeBodySegment(i));
    }
    snakelinkedlist::LinkedList test_linkedlist = snakelinkedlist::LinkedList(test_values);
    
    REQUIRE(test_linkedlist.size() != 0);
}

TEST_CASE("inserting node at head test") {
    std::vector<snakelinkedlist::SnakeBodySegment> values;
    int vector_length = 5;
    for (int i = 0; i < vector_length; i++) { //adding values to snake vector
        values.push_back(snakelinkedlist::SnakeBodySegment(i));
    }
    snakelinkedlist::LinkedList expected_linkedlist = snakelinkedlist::LinkedList(values);
    std::vector<snakelinkedlist::SnakeBodySegment> test_values;
    for (int i = 1; i < vector_length; i++) { //adding values to snake vector except first value
        test_values.push_back(snakelinkedlist::SnakeBodySegment(i));
    }
    snakelinkedlist::LinkedList test_linkedlist = snakelinkedlist::LinkedList(test_values);
    snakelinkedlist::SnakeBodySegment value_inserted = snakelinkedlist::SnakeBodySegment(0); //so inserting value 0 to linked list
    test_linkedlist.push_front(value_inserted);
    
    REQUIRE(test_linkedlist == expected_linkedlist);
}

TEST_CASE("inserting node at tail test") {
    std::vector<snakelinkedlist::SnakeBodySegment> values;
    int vector_length = 5;
    for (int i = 0; i < vector_length; i++) {
        values.push_back(snakelinkedlist::SnakeBodySegment(i));
    }
    snakelinkedlist::LinkedList actual_linkedlist = snakelinkedlist::LinkedList(values);
    snakelinkedlist::SnakeBodySegment value_inserted = snakelinkedlist::SnakeBodySegment(0);
    values.push_back(value_inserted);
    snakelinkedlist::LinkedList expected_linkedlist = snakelinkedlist::LinkedList(values);
    actual_linkedlist.push_back(value_inserted);
    
    REQUIRE(actual_linkedlist == expected_linkedlist);
}

TEST_CASE("pop_front() test") {
    std::vector<snakelinkedlist::SnakeBodySegment> values;
    int vector_length = 5;
    for (int i = 0; i < vector_length; i++) {
        values.push_back(snakelinkedlist::SnakeBodySegment(i));
    }
    snakelinkedlist::LinkedList actual_linkedlist = snakelinkedlist::LinkedList(values);
    values.erase(values.begin()); //erases first element of the vector of SnakeBodySegements
    snakelinkedlist::LinkedList expected_linkedlist = snakelinkedlist::LinkedList(values);
    actual_linkedlist.pop_front();
    
    REQUIRE(actual_linkedlist == expected_linkedlist);
}

TEST_CASE("pop_back() test") {
    std::vector<snakelinkedlist::SnakeBodySegment> values;
    int vector_length = 5;
    for (int i = 0; i < vector_length; i++) {
        values.push_back(snakelinkedlist::SnakeBodySegment(i));
    }
    snakelinkedlist::LinkedList actual_linkedlist = snakelinkedlist::LinkedList(values);
    values.erase(values.begin() + vector_length - 1); //erases last element of the vector of SnakeBodySegements
    snakelinkedlist::LinkedList expected_linkedlist = snakelinkedlist::LinkedList(values);
    actual_linkedlist.pop_back();
    
    REQUIRE(actual_linkedlist == expected_linkedlist);
}

TEST_CASE("RemoveNth Node test") {
    std::vector<snakelinkedlist::SnakeBodySegment> values;
    int vector_length = 5;
    for (int i = 0; i < vector_length; i++) {
        values.push_back(snakelinkedlist::SnakeBodySegment(i));
    }
    snakelinkedlist::LinkedList actual_linkedlist = snakelinkedlist::LinkedList(values);
    int third_pos = 3;
    values.erase(values.begin() + third_pos - 1); //erases third element of the vector of SnakeBodySegements
    snakelinkedlist::LinkedList expected_linkedlist = snakelinkedlist::LinkedList(values);
    actual_linkedlist.RemoveNth(third_pos);
    
    REQUIRE(actual_linkedlist == expected_linkedlist);
}

TEST_CASE("clear() test") {
    std::vector<snakelinkedlist::SnakeBodySegment> values;
    int vector_length = 5;
    for (int i = 0; i < vector_length; i++) {
        values.push_back(snakelinkedlist::SnakeBodySegment(i));
    }
    snakelinkedlist::LinkedList actual_linkedlist = snakelinkedlist::LinkedList(values);
    snakelinkedlist::LinkedList empty_linkedlist = snakelinkedlist::LinkedList();
    actual_linkedlist.clear();
    
    REQUIRE(actual_linkedlist == empty_linkedlist);
}

TEST_CASE("front() test") {
    std::vector<snakelinkedlist::SnakeBodySegment> values;
    int vector_length = 5;
    for (int i = 0; i < vector_length; i++) {
        values.push_back(snakelinkedlist::SnakeBodySegment(i));
    }
    snakelinkedlist::LinkedList actual_linkedlist = snakelinkedlist::LinkedList(values);
    int front_value = 0;
    
    REQUIRE(actual_linkedlist.front() == front_value);
}

TEST_CASE("back() test") {
    std::vector<snakelinkedlist::SnakeBodySegment> values;
    int vector_length = 5;
    for (int i = 0; i < vector_length; i++) {
        values.push_back(snakelinkedlist::SnakeBodySegment(i));
    }
    snakelinkedlist::LinkedList actual_linkedlist = snakelinkedlist::LinkedList(values);
    int last_value = 4;
    
    REQUIRE(actual_linkedlist.back() == last_value);
}

TEST_CASE("size() test") {
    std::vector<snakelinkedlist::SnakeBodySegment> values;
    int vector_length = 5;
    for (int i = 0; i < vector_length; i++) {
        values.push_back(snakelinkedlist::SnakeBodySegment(i));
    }
    snakelinkedlist::LinkedList actual_linkedlist = snakelinkedlist::LinkedList(values);
    int size = vector_length;
    
    REQUIRE(actual_linkedlist.size() == size);
}

TEST_CASE("GetVector() test") {
    std::vector<snakelinkedlist::SnakeBodySegment> values;
    int vector_length = 5;
    for (int i = 0; i < vector_length; i++) {
        values.push_back(snakelinkedlist::SnakeBodySegment(i));
    }
    snakelinkedlist::LinkedList actual_linkedlist = snakelinkedlist::LinkedList(values);
    
    REQUIRE(actual_linkedlist.GetVector() == values);
}

TEST_CASE("empty() true test") {
    snakelinkedlist::LinkedList actual_linkedlist = snakelinkedlist::LinkedList();
    REQUIRE(actual_linkedlist.empty() == true);
}

TEST_CASE("empty() false test") {
    std::vector<snakelinkedlist::SnakeBodySegment> values;
    int vector_length = 5;
    for (int i = 0; i < vector_length; i++) {
        values.push_back(snakelinkedlist::SnakeBodySegment(i));
    }
    snakelinkedlist::LinkedList actual_linkedlist = snakelinkedlist::LinkedList(values);
    
    REQUIRE(actual_linkedlist.empty() == false);
}

TEST_CASE("iterator operator++ test") {
    snakelinkedlist::Iterator test;
}

TEST_CASE("iterator operator* test") {
    
}
