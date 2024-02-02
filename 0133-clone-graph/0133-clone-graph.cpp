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
    Node * dfs(Node* node, map<Node *, Node *> &mp){
        if (mp[node])return mp[node];
        Node * tmp = new Node(node->val);
        mp[node] = tmp;
        for (Node * nei : node->neighbors){
            tmp->neighbors.push_back(dfs(nei,mp));
        }
        return tmp;
    }
    Node* cloneGraph(Node* node) {
        map<Node *, Node *>mp;
        if (node == nullptr) return nullptr;
        return dfs(node,mp);
    }
};