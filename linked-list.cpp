#include "linked-list.hpp"

/**
 * (Hopefully straightforward) test application.
 */
int main() {
    LinkedList* list = new LinkedList();
    
    list->add(5);
    list->add(10);
    list->add(17);
    
    list->remove(5);
    list->print();
}