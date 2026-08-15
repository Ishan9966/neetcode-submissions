/*
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
*/

class Solution {
   public:
    Node* clone(Node* node, unordered_map<Node*, Node*>& hash) {
        Node* newNode = new Node(node->val);
        hash[node]=newNode;
        for (auto n : node->neighbors) {
            if (hash.find(n) == hash.end()) {
                newNode->neighbors.push_back(clone(n,hash));
            } else {
                newNode->neighbors.push_back(hash[n]);
            }
        }
        return newNode;
    }

    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        unordered_map<Node*, Node*> hash;
        return clone(node, hash);
    }
};
