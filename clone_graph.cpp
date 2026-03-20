#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> mapping;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        if (mapping.find(node) != mapping.end()) {
            return mapping[node];
        }

        Node* clone = new Node(node->val);
        mapping[node] = clone;

        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};

// ----------- Helper for testing -----------
void printGraph(Node* node, unordered_set<Node*>& visited) {
    if (!node || visited.count(node)) return;

    visited.insert(node);
    cout << "Node " << node->val << " -> ";

    for (auto n : node->neighbors) {
        cout << n->val << " ";
    }
    cout << endl;

    for (auto n : node->neighbors) {
        printGraph(n, visited);
    }
}

int main() {
    // Create sample graph:
    // 1 -- 2
    // |    |
    // 4 -- 3

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    Solution sol;
    Node* cloned = sol.cloneGraph(n1);

    unordered_set<Node*> visited;
    cout << "Cloned Graph:\n";
    printGraph(cloned, visited);

    return 0;
}