#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

// void insert(int x, int n) {
//     Node* curr = new Node();
//     curr->data = x;
//     curr->next = head;
//     head = curr;
// }

void insert(int x, int n) {
    Node* temp1 = new Node();
    temp1->data = x;
    temp1->next = NULL;
    if (n == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }  
    Node* temp2 = head;
    for (int i=0; i<n-2; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void deleteNode(int n) {
    Node* temp1 = head;
    // Go to n-1 node
    // if n == 1, then head is to be deleted
    if (n == 1) {
        head = temp1->next;
        delete temp1;
        return;
    }
    for (int i=0; i<n-2; i++) {
        temp1 = temp1->next;
    }
    // Get the n node (that we want to delete)
    Node* temp2 = temp1->next;
    temp1->next = temp2->next; // n+1 node
    // Free node n from memory
    delete temp2;
}

void print() {
    Node* curr = head;
    while(curr != NULL) {
        cout << curr->data << " - ";
        curr = curr->next;
    }
    cout << endl;

}

void reverse() {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr  = next;
    }
    head = prev;
    return;
}

void printReverse(Node* curr) {
    if (curr == NULL) return;
    printReverse(curr->next);
    cout << curr->data << " - ";
    return;
}

int main() {
    //Node* h = head;
    //printf("How many numbers?\n");
    // int n, i, x;
    // scanf("%d", &n);
    // for (i=0; i<n; i++) {
    //     printf("Enter the number: ");
    //     scanf("%d", &x);
    //     print();
    // }
    // insert
    insert(3, 1);
    insert(4, 2);
    insert(5, 1);
    insert(8, 4);
    print();
    deleteNode(1);
    print();
    reverse();
    print();
    printReverse(head);
}
