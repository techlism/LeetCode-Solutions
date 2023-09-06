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
private: 
    Node * cloneDFS(Node * node, unordered_map<Node *,Node *> &oldNew){
        if(oldNew.find(node) != oldNew.end()){
            return oldNew[node];
        }
        Node * copy = new Node(node->val);
        oldNew[node] = copy;
        for(auto n : node->neighbors){
            copy->neighbors.push_back(cloneDFS(n,oldNew));
        }
        return copy;
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        unordered_map<Node*,Node*> oldNew;
        return cloneDFS(node,oldNew);
    }
};