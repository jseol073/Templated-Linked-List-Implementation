#include <utility>
#include "../src/ll.h"

    template<typename ElementType>
    snakelinkedlist::LinkedList<ElementType>::LinkedList() : list_head(nullptr), size_(0) {
    }
    
    template<typename ElementType>
   snakelinkedlist::LinkedList<ElementType>::LinkedList(const std::vector<ElementType> &values) : list_head(nullptr), size_(0) {
        if (values == NULL || values.size() != 0) {
            list_head = new LinkedListNode(values.at(0));
            size_++;
            LinkedListNode *temp = list_head;
            for (int i = 1; i < values.size(); i++) {
                temp -> next_ = new LinkedListNode(values.at(i));
                temp = temp -> next_;
                size_++;
            }
        } else {
            list_head = nullptr;
        }
    }
    
    // Copy constructor
    template<typename ElementType>
    snakelinkedlist::LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {
        if (source.list_head) {
            LinkedListNode *temp = list_head;
            while (temp) {
                temp = new LinkedListNode(*source.list_head);
                temp = temp -> next;
            }
        } else {
            list_head = nullptr;
        }
    }
    
    // Move constructor
    template<typename ElementType>
    snakelinkedlist::LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {
        list_head = source.list_head;
        source.list_head = nullptr;
    }
    
    // Destructor
    template<typename ElementType>
    snakelinkedlist::LinkedList<ElementType>::~LinkedList() {
        clear();
    }
    
    // Copy assignment operator
    template<typename ElementType>
    snakelinkedlist::LinkedList<ElementType> &snakelinkedlist::LinkedList<ElementType>::operator=(const LinkedList<ElementType>& source) {
        if(this == &source) {
            return *this;
        }
        clear();
        list_head = nullptr;
        LinkedListNode *temp = list_head;
        LinkedListNode *source_node = source.list_head;
        while (source_node) {
            temp = new LinkedListNode(source_node -> data_);
            source_node = source_node -> next_;
            temp = temp -> next_;
            size_++;
        }
        return *this;
    }
    
    // Move assignment operator
    template<typename ElementType>
    snakelinkedlist::LinkedList<ElementType>& snakelinkedlist::LinkedList<ElementType>::operator=(snakelinkedlist::LinkedList<ElementType>&& source) noexcept {
        if(this == &source) {
            return *this; }
        delete list_head;
        list_head = source.string_;
        source.string_ = nullptr;
        return *this;
    }
    
    template<typename ElementType>
    void snakelinkedlist::LinkedList<ElementType>::push_front(ElementType value) {
        LinkedListNode *new_node = new LinkedListNode(value);
        new_node -> next_ = list_head;
        list_head = new_node;
        size_++;
    }
    
    template<typename ElementType>
    void snakelinkedlist::LinkedList<ElementType>::push_back(ElementType value) {
        LinkedListNode *new_node = new LinkedListNode(value);
        new_node -> next_ = NULL;
        if (list_head == NULL) {
            list_head = new_node;
        } else {
            LinkedListNode *temp = list_head;
            // Uses temp to find the last node
            while (temp) {
                temp = temp -> next_;
            }
            temp = new_node;
        }
        size_++;
    }
    
    template<typename ElementType>
    ElementType snakelinkedlist::LinkedList<ElementType>::front() const{
        if (list_head == NULL) {
            return ElementType();
        }
        ElementType first_value = list_head -> data_;
        return first_value;
    }
    
    template<typename ElementType>
    ElementType snakelinkedlist::LinkedList<ElementType>::back() const {
        if (list_head == NULL) {
            return ElementType();
        }
        LinkedListNode *temp = list_head;
        while (temp -> next != NULL) {
            temp = temp -> next_;
        }
        ElementType last_value = temp -> data_;
        return last_value;
    }
    
    template<typename ElementType>
    void snakelinkedlist::LinkedList<ElementType>::pop_front() {
        if(!list_head) {
            return;
        }
        LinkedListNode *tmp = list_head;
        list_head = list_head -> next;
        delete tmp;
        size_--;
    }
    
    template<typename ElementType>
    void snakelinkedlist::LinkedList<ElementType>::pop_back() {
        if(!list_head) {
            return;
        }
        LinkedListNode *remove_next = list_head;
        while(remove_next) {
            remove_next = remove_next -> next_;
        }
        delete remove_next;
        size_--;
    }
    
    template<typename ElementType>
    int snakelinkedlist::LinkedList<ElementType>::size() const {
        return size_;
    }
    
    template<typename ElementType>
    std::vector<ElementType> snakelinkedlist::LinkedList<ElementType>::GetVector() const {
        std::vector<ElementType> list_to_vector;
        LinkedListNode *temp = list_head;
        while (temp) {
            list_to_vector.push_back(temp -> data_);
            temp = temp -> next_;
        }
        return list_to_vector;
    }
    
    template<typename ElementType>
    bool snakelinkedlist::LinkedList<ElementType>::empty() const {
        if (list_head == nullptr) {
            return true;
        }
        return false;
    }
    
    template<typename ElementType>
    void snakelinkedlist::LinkedList<ElementType>::clear() {
        LinkedListNode *next_ = list_head;
        while(next_) {
            LinkedListNode *deleteMe = next_;
            next_ = next_ -> next;
            delete deleteMe;
        }
        size_ = 0;
        list_head = nullptr;
    }
    
    template<typename ElementType>
    std::ostream& operator<<(std::ostream& os, const snakelinkedlist::LinkedList<ElementType>& list) {
        snakelinkedlist::LinkedList<ElementType> copy_list = list;
        for(int i = 0; i < list.size(); i++) {
            os << copy_list.list_head -> data_ << ", ";
            copy_list.list_head = copy_list.list_head -> next_;
        }
        return os;
    }
    
    template<typename ElementType>
    void snakelinkedlist::LinkedList<ElementType>::RemoveNth(int n) {
        if (!list_head) {
            return;
        }
        LinkedListNode *current = list_head;
        LinkedListNode *prev = new LinkedListNode(NULL);
        
        for (int i = 1; i < n; i++) {
            prev = current;
            current = current -> next;
        }
        prev -> next = current -> next;
        size_--;
    }
    
    template<typename ElementType>
bool snakelinkedlist::LinkedList<ElementType>::operator==(const snakelinkedlist::LinkedList<ElementType> &rhs) const {
        if ((*this).size() != rhs.size()) {
            return false;
        } else {
            LinkedListNode *temp_this = list_head;
            LinkedListNode *temp_rhs = rhs.list_head;
            while (temp_this && temp_rhs) {
                if (temp_this -> data_ != temp_rhs -> data_) {
                    return false;
                } else {
                    temp_this = temp_this -> next_;
                    temp_rhs = temp_rhs -> next_;
                }
            }
        }
        return true;
    }
    
    template<typename ElementType>
    bool operator!=(const snakelinkedlist::LinkedList<ElementType>& lhs, const snakelinkedlist::LinkedList<ElementType> &rhs) {
        return !(lhs == rhs);
    }
    
    template<typename ElementType>
    typename snakelinkedlist::LinkedList<ElementType>::Iterator& snakelinkedlist::LinkedList<ElementType>::Iterator::operator++() {
        if (current_) {
            current_ = current_ -> next_;
        }
        return *this;
    }
    
    template<typename ElementType>
    ElementType& snakelinkedlist::LinkedList<ElementType>::Iterator::operator*() {
        return current_ -> data_;
    }
    
    template<typename ElementType>
    bool snakelinkedlist::LinkedList<ElementType>::Iterator::operator!=(const snakelinkedlist::LinkedList<ElementType>::Iterator& other) {
        return (current_ != other.current_);
    }
    
    template<typename ElementType>
    typename snakelinkedlist::LinkedList<ElementType>::Iterator snakelinkedlist::LinkedList<ElementType>::begin() {
        Iterator start;
        start.current_ = list_head;
        return start;
    }
    
    template<typename ElementType>
    typename snakelinkedlist::LinkedList<ElementType>::Iterator snakelinkedlist::LinkedList<ElementType>::end() {
        Iterator end;
        end.current_ = nullptr;
        return end;
    }
