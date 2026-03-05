#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* slist = new ListNode(0, nullptr);
        ListNode* blist = new ListNode(0, nullptr);
        ListNode* small = slist;
        ListNode* big = blist;

        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } 
            else {
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }

        small->next = blist->next;
        big->next = nullptr;

        ListNode* result = slist->next;
        delete slist;
        delete blist;

        return result;
    }
};

void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {

    // Creating linked list: 1 -> 4 -> 3 -> 2 -> 5 -> 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;

    Solution obj;
    ListNode* result = obj.partition(head, x);

    cout << "Partitioned List: ";
    printList(result);

    return 0;
}