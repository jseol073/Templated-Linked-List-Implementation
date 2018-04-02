#include "ll.h"

using namespace std;

namespace snakelinkedlist {
    
    LinkedList::LinkedList() : list_head(NULL) {
    }
    
    LinkedList::LinkedList(const std::vector<SnakeBodySegment>& values) {
        
    }
    
    LinkedList::LinkedList(const LinkedList& source) {
        if (source.list_head) {
            list_head = new Node(*source.list_head);
        } else {
            list_head = nullptr;
        }
    }
    
    LinkedList::LinkedList(LinkedList&& source) noexcept {
        list_head = source.list_head;
        source.list_head = nullptr;
    }
    
    LinkedList::~LinkedList() {
        delete list_head;
    }
    
//    LinkedList::LinkedList& operator=(const LinkedList& source) {
//        if(this == &source) {
//            return;
//        }
//        delete list_head;
//        list_head = nullptr;
//        if(source.list_head) {
//            list_head = new Node(*source.list_head);
//        }
//        return *this;
//    }
    
//    bool operator!=(const LinkedList& lhs, const LinkedList& rhs) {
//
//    }

} // namespace snakelinkedlist
