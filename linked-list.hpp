#include <iostream>

/**
 * A LinkedList is a container that we can add or remove things to. It's very fast
 * to add and remove new elements, as well as to iterate over elements. It's slower
 * than an array for indexing (random access) since all operations must start at the 
 * head.
 */
class LinkedList {
    /**
     * A ListNode is an individual item in a list. It contains a value as well as a 
     * pointer to the next item in the list. We use the pointer to iterate from item 
     * to item. This implemention is a "singly-linked list":
     *
     *   https://en.wikipedia.org/wiki/Linked_list#Singly_linked_list
     *
     * If you add a pointer to the previous element (often called prev), it'll become
     * a "doubly-linked list." The only difference is that doubly-linked lists are
     * quick to traverse in forward and reverse order.
     */
    struct ListNode {
        int value;
        ListNode* next;
    };

    ListNode* start;
    
    public:
    LinkedList() {
        start = NULL;
    }
    
    /**
     * Add an item to the front of the list. If you want to add it to the back, you should
     * keep track of an 'end' pointer in addition to the 'start' one, and modify that.
     */
    void add(int value) {
        // Create a new node for our new value.
        ListNode* node = new ListNode();
        node->value = value;
        node->next = NULL;
        
        // Give it a home!
        ListNode* caboose = start;
        start = node;
        start->next = caboose;
    }
    
    /**
     * Remove the first item we come across with the specified value. Do nothing if 
     * the value doesn't exist. This function also deallocates the ListItem (if found).
     */
    void remove(int value) {
        ListNode* current = start;
        
        // still has an error!
        // 1) memory leak! (fixed)
        // 2) break when current->next == NULL (fixed)
        
        // as long as there's a next item and its value is not VALUE, keep looking
        while (current->next != NULL && current->next->value != value) {
            current = current->next;
        }
        
        // if we terminate and find it, change it. if we don't find it, skip it
        if (current->next != NULL) {
            // ListNode* toRemove = current->next;
            delete current->next;
            current->next = current->next->next;
        }
    }
    
    /**
     * Helper function whose sole purpose in life is to print out what the list currently
     * looks like with some ascii art.
     */
    void print() {
        ListNode* current = start;
        while(current != NULL) {
            std::cout << "[ " << current->value << " ] ==> ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    // add / assign something to it
    //   - potentially complex data!
    // take something away from it
    // read something on it
};