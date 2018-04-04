#include "ll.h"

using namespace std;

namespace snakelinkedlist {
    
    LinkedList::LinkedList() : list_head(NULL) {
        length = 0;
    }
    
    LinkedList::LinkedList(const std::vector<SnakeBodySegment>& values) {
        length = 0;
        if (values.size() != 0) {
            list_head = new Node(values.at(0));
            length++;
            Node *temp = list_head;
            for (int i = 1; i < values.size(); i++) {
                temp -> next = new Node(values.at(i));
                temp = temp -> next;
                length++;
            }
        } else {
            list_head = nullptr;
        }
    }
    
    LinkedList::LinkedList(const LinkedList& source) {
        if (source.list_head) {
            Node *temp = list_head;
            while (temp) {
                temp = new Node(*source.list_head);
                temp = temp -> next;
            }
        } else {
            list_head = nullptr;
        }
    }
    
    LinkedList::LinkedList(LinkedList&& source) noexcept {
        if (source.list_head) {
            Node *temp = list_head;
            Node *source_node = source.list_head;
            while (temp) {
                temp = new Node(*source.list_head);
                delete source_node;
                temp = temp -> next;
                source_node = source_node -> next;
            }
        } else {
            list_head = nullptr;
            source.list_head = nullptr;
        }
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
        Node *new_node = new Node(value);
        new_node -> next = NULL;
        if (list_head == NULL) {
            list_head = new_node;
        } else {
            Node *temp = list_head;
            // Uses temp to find the last node
            while (temp) {
                temp = temp -> next;
            }
            temp = new_node;
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
        while(remove_next) {
            remove_next = remove_next -> next;
        }
        delete remove_next;
        length--;
    }
    
    void LinkedList::RemoveNth(int n) {
        if (!list_head) {
            return;
        }
        Node *current = list_head;
        Node *prev = new Node(NULL);
        
        for (int i = 1; i < n; i++) {
            prev = current;
            current = current -> next;
        }
        prev -> next = current -> next;
        length--;
    }
    
    void LinkedList::clear() {
        Node *next_ = list_head;
        while(next_) {
            Node *deleteMe = next_;
            next_ = next_ -> next;
            delete deleteMe;
        }
        length = 0;
        list_head = nullptr;
    }
    
    SnakeBodySegment LinkedList::front() const {
        if (list_head == NULL) {
            return SnakeBodySegment();
        }
        SnakeBodySegment first_value = list_head -> data;
        return first_value;
    }
    
    SnakeBodySegment LinkedList::back() const {
        if (list_head == NULL) {
            return SnakeBodySegment();
        }
        Node *temp = list_head;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        SnakeBodySegment last_value = temp -> data;
        return last_value;
    }
    
    int LinkedList::size() const {
        return length;
    }
    
    std::vector<SnakeBodySegment> LinkedList::GetVector() const {
        std::vector<SnakeBodySegment> list_to_vector;
        Node *temp = list_head;
        while (temp) {
            list_to_vector.push_back(temp -> data);
            temp = temp -> next;
        }
        return list_to_vector;
    }
    
    bool LinkedList::empty() const {
        if (list_head == nullptr) {
            return true;
        }
        return false;
    }
    
    std::ostream& operator<<(std::ostream& os, const LinkedList &list) {
        LinkedList copy_list = list;
        for(int i = 0; i < list.size(); i++) {
            os << copy_list.list_head -> data << ", ";
            copy_list.list_head = copy_list.list_head -> next;
        }
        return os;
    }
    
    bool LinkedList::operator==(const LinkedList& rhs) const {
        if ((*this).size() != rhs.size()) {
            return false;
        } else {
            Node *temp_this = list_head;
            Node *temp_rhs = rhs.list_head;
            while (temp_this && temp_rhs) {
                if (temp_this -> data != temp_rhs -> data) {
                    return false;
                } else {
                    temp_this = temp_this -> next;
                    temp_rhs = temp_rhs -> next;
                }
            }
        }
        return true;
    }
    
    LinkedList& LinkedList::operator=(const LinkedList& source) {
        if(this == &source) {
            return *this;
        }
        clear();
        list_head = nullptr;
        Node *temp = list_head;
        Node *source_node = source.list_head;
        while (source_node) {
            temp = new Node(source_node -> data);
            source_node = source_node -> next;
            temp = temp -> next;
            length++;
        }
        return *this;
    }
    
    bool operator!=(const LinkedList& lhs, const LinkedList& rhs) {
        return !(lhs == rhs);
    }
} // namespace snakelinkedlist
