#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    // Merge two sorted linked lists
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        // Attach remaining nodes
        if (l1 != NULL)
            curr->next = l1;

        if (l2 != NULL)
            curr->next = l2;

        return dummy.next;
    }

    // Merge sort on linked list
    ListNode* sortList(ListNode* head) {

        // Base case
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // Find middle using slow-fast pointer
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split list into two halves
        prev->next = NULL;

        // Recursive sorting
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return mergeList(l1, l2);
    }
};

// Helper function to print list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Driver code for testing
int main() {

    // Creating sample list: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution obj;

    cout << "Original List:\n";
    printList(head);

    head = obj.sortList(head);

    cout << "Sorted List:\n";
    printList(head);

    return 0;
}