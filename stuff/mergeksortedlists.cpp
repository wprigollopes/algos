#include<iostream>
#include<vector>
#include<queue>

using namespace std;
// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
struct compare {
    bool operator()(struct ListNode* lhs, struct ListNode* rhs) {
        return lhs->val < rhs->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // The head that we return
        ListNode* head; // Head to return
        ListNode* curr; // Current to control
        ListNode* last; // Last to reference
        // Create a priority queue comparing the values
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        // Get first values from k linked lists
        for (int k=0; k<lists.size(); k++) {
            if (lists[k] != nullptr) {
                ListNode* node = lists[k];
                pq.push(node);
        }
        // Traverse the priority queue
        while(!pq.empty()) {
            // Get the value
            ListNode* node = pq.top();
            // Remove from heap
            pq.pop();
            // And insert the next value from the linked list
            if (node !=nullptr) {
                pq.push(node->next);
            }
            // If the head is null, so, insert the actual node
            if (head == nullptr) {
                head = node;
                last = node;
            } else {
                // Else, checks
                last->next = curr;
                last = curr;
            }
        }
        return head;
    }
};