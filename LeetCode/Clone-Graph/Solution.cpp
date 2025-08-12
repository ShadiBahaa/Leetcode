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
    map<int,Node *> mp;
    Node* cloneGraph(Node* node) {
        if(node == nullptr)return nullptr;
        if(mp.count(node->val))return mp[node->val];
        Node * newNode = new Node(node->val);
        mp[newNode->val] = newNode;
        if(node->neighbors.size()){
            for (Node * child : node->neighbors){
            Node * tmp = cloneGraph(child);
            newNode->neighbors.push_back(tmp);
        }
        }
        return newNode;
    }
};