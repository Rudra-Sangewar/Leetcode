#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        int length = 1;
        ListNode* dummy = head;

        while (dummy->next) {
            dummy = dummy->next;
            length++;
        }

        int position = k % length;
        if (position == 0) return head;

        ListNode* current = head;
        for (int i = 0; i < length - position - 1; i++) {
            current = current->next;
        }

        ListNode* newHead = current->next;
        current->next = nullptr;
        dummy->next = head;

        return newHead;
    }
};

// Helper function to create linked list
ListNode* createList(vector<int>& v) {
    if (v.empty()) return nullptr;

    ListNode* head = new ListNode(v[0]);
    ListNode* temp = head;

    for (int i = 1; i < v.size(); i++) {
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode* head = createList(v);

    Solution obj;
    ListNode* result = obj.rotateRight(head, k);

    printList(result);

    return 0;
}
