#include<iostream>
#include<unordered_map>
#include<set>
//
// LRU Cache - Least Recently Used Cache
// Uses a technique called Hash Linked List to get a good efficiency on getting and updating cache status
//


using namespace std;
//
// Doubly linked list
// 
class DoublyLinkedListNode {
    public:
        int key;
        int value;
        DoublyLinkedListNode* next;
        DoublyLinkedListNode* prev;

    // Update the doubly linked list node
    DoublyLinkedListNode(int key, int value) {
        this->key = key;
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
    
    // Clean the bindings
    void removeBindings() {
        if (this->prev != nullptr) {
            this->prev->next = nullptr;
        }
        if (this->next != nullptr) {
            this->next->prev = nullptr;
        }
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoublyLinkedList {
    public:
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;

    // 
    void setHeadTo(DoublyLinkedListNode *node) {
        // If head is node - do nothing
        if (this->head == node) {
            return;
        // if head is empty - head and tail to node
        } else if (this->head == nullptr) {
            this->head = node;
            this->tail = node;
        // if head is equal to tail (unique node)
        } else if (this->head == this->tail) {
            this->tail->prev = node;
            this->head = node;
            this->head->next = tail;
        } else {
            if (this->tail == node) {
                this->removeTail();
            }
            node->removeBindings();
            this->head->prev = node;
            node->next = this->head;
            this->head = node;
        }
    }
    
    void removeTail() {
        if (this->tail == nullptr) {
            return;
        }  else if (this->tail == this->head) {
            this->head = nullptr;
            this->tail = nullptr;
            return;
        }
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
        return;
    }
};
//
// Doubly linked list end
//


//
// LRU cache, using hash and doubly linked list to access and order elements
//
class LRUCache {
public:
    // Hashset from doubly linked list
    unordered_map<int, DoublyLinkedListNode *> cache;
    // Max size
    int maxSize;
    // Control to current size
    int currentSize;
    // List of most recent elements
    DoublyLinkedList listOfMostRecent;
    
    // Constructor
    LRUCache(int capacity) {
        this->maxSize = capacity>1 ? capacity : 1;
        this->currentSize = 0;
        this->listOfMostRecent = DoublyLinkedList();
    }
    
    // get the head value
    int get(int key) {
        int value = this->listOfMostRecent.head->value;
        if (key == value) {
            return key;
        } else {
            return -1;
        }
    }
    
    // Put a value
    void put(int key, int value) {
        if (this->cache.find(key) == this->cache.end()) {
            if (this->currentSize == this->maxSize) {
                this->evictLastRecent();
            } else {
                this->currentSize++;
            }
            this->cache[key] = new DoublyLinkedListNode(key, value);
        } else {
            this->replaceKey(key, value);
        }
        this->updateMostRecent(this->cache[key]);
    }
    
    // Helper to remove last recent when the cache is full
    void evictLastRecent() {
        int keyToRemove = this->listOfMostRecent.tail->key;
        this->listOfMostRecent.removeTail();
        this->cache.erase(keyToRemove);
    }
    
    // Update the element to most recent if already exits (update to acccess)
    void updateMostRecent(DoublyLinkedListNode* node) {
        this->listOfMostRecent.setHeadTo(node);
    }
    
    // Replace a value when element already exists
    void replaceKey(int key, int value) {
        if (this->cache.find(key) == this->cache.end()) {
            return;
        }
        this->cache[key]->value = value;
    }
};

int main() {
    LRUCache *cache = new LRUCache(2);
    cache->put(1,1);
    cache->put(2,2);
    cout << cache->get(1) << endl;
    cache->put(3,3);
    cout << cache->get(2) << endl;
    cache->put(4,4);
    cout << cache->get(1) << endl;
    cout << cache->get(3) << endl;
    cout <<cache->get(4) << endl;
    return 0;
}
