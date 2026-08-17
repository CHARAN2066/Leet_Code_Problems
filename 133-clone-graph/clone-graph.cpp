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
    Node* cloneGraph(Node* node) {
        if (node == NULL)
        return NULL;
        vector<vector<int>> adj(101);
        vector<int> visted(101, 0);
        queue<Node*> q;
        q.push(node);
        Node* temp;
        visted[1] = 1;
        int n = 0;
        while (!q.empty()) {
            temp = q.front();
            n = max(temp->val, n);
            q.pop();
            for (auto i:temp->neighbors) {
                adj[temp -> val].push_back(i->val);
                if (!visted[i->val])
                q.push(i);
                visted[i->val] = 1;
            }
        }
        vector<Node*> nodes(n, NULL);
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i+1);   
        }
        cout<< n<< endl;
        for (int i = 0; i < n; i++) {
            for (auto j:adj[i + 1]) {
                nodes[i]->neighbors.push_back(nodes[j - 1]);
            }
        }
        if (n == 0)
        return NULL;
        return nodes[0];
    }
};