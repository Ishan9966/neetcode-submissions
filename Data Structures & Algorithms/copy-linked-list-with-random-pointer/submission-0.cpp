/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hash;
        if (head == nullptr) return nullptr;

        Node* newHead = new Node(head->val);
        Node* t = head->next;
        Node* nt = newHead;
        while (t != nullptr) {
            nt->next = new Node(t->val);
            hash[t] = nt->next;
            t = t->next;
            nt = nt->next;
        }

        t = head;
        nt = newHead;
        hash[head] = newHead;
        while (t != nullptr) {
            nt->random = hash[t->random];
            t = t->next;
            nt = nt->next;
        }

        return newHead;
    }
};
