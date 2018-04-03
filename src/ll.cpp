#include "ll.h"

using namespace std;

namespace snakelinkedlist {
    
    LinkedList::LinkedList() : list_head(NULL) {
        length = 0;
    }
    
    LinkedList::LinkedList(const std::vector<SnakeBodySegment>& values) {
        //init head
        //
        //for each snakeSegment values
        //  make a node
        //  add the node to the linked_list using only a single pointer
        
        length = values.size();
        list_head = new Node(values.at(0));
        Node* tmp = list_head;
        
        for (auto segment : values) {
            tmp -> next = new Node(segment);
            tmp = tmp -> next;
        }
        delete tmp;
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
        clear();
    }
    
    void LinkedList::push_front(SnakeBodySegment value) {
        Node *new_node = new Node(value);
        new_node -> next = list_head;
        list_head = new_node;
        length++;
    }
    
    void LinkedList::push_back(SnakeBodySegment value) {
        if(!list_head) {
            return;
        }
        Node *new_node = new Node(value);
        new_node -> next = NULL;
        if (list_head == NULL) {
            list_head  = new_node;
            return;
        } else {
            Node *temp = new Node(value);
            temp = list_head;
            
            // Uses temp to find the last node
            while (temp -> next != NULL) {
                temp = temp -> next;
            }
            temp -> next = new_node;
        }
        length++;
    }
    
    void LinkedList::pop_front() {
        if(!list_head) {
            return;
        }
        Node *tmp = list_head;
        list_head = list_head -> next;
        delete tmp;
        length--;
    }
    
    void LinkedList::pop_back() {
        if(!list_head) {
            return;
        }
        Node *remove_next = list_head;
        while(remove_next -> next && remove_next -> next -> next) {
            remove_next = remove_next -> next;
        }
        delete remove_next -> next;
        remove_next = nullptr;
        length--;
    }
    
    void LinkedList::RemoveNth(int n) {
        Node *current = list_head;
        Node *prev = new Node(NULL);
        
        for(int i = 1; i < n; i++) {
            prev = current;
            current = current -> next;
        }
        prev -> next = current -> next;
        length--;
    }
    
    void LinkedList::clear() {
        Node *current = list_head;
        while(current != NULL ) {
            Node* next_ = current -> next;
            delete current;
            current = next_;
        }
        list_head = NULL;
        length = 0;
    }
    
    SnakeBodySegment LinkedList::front() const {
        if (list_head == NULL) {
            return SnakeBodySegment();
        }
        return list_head -> data;
    }
    
    SnakeBodySegment LinkedList::back() const {
        if (list_head == NULL) {
            return SnakeBodySegment();
        }
        while (list_head -> next != NULL) {
            //list_head = list_head -> next;
        }
        return list_head -> data;
    }
    
    int LinkedList::size() const {
        return length;
    }
    
    std::vector<SnakeBodySegment> LinkedList::GetVector() const {
        std::vector<SnakeBodySegment> list_to_vector;
        Node *temp = list_head;
        while (temp -> next != NULL) {
            list_to_vector.push_back(temp -> data);
            temp = temp -> next;
        }
        return list_to_vector;
    }
    
    std::ostream & operator<<(std::ostream& os, const LinkedList &list) {
        LinkedList copy_list = list;
        for(int i = 0; i < list.size(); i++) {
            os << copy_list.list_head -> data << ", ";
            copy_list.list_head = copy_list.list_head -> next;
        }
        return os;
    }
    
    bool LinkedList::operator==(const LinkedList& rhs) const {
        
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
    
    bool operator!=(const LinkedList& lhs, const LinkedList& rhs) {
        return !(lhs == rhs);
    }

} // namespace snakelinkedlist
