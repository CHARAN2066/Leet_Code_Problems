class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> outdegree(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            outdegree[i] = (graph[i].size());
            if (outdegree[i] == 0)
            q.push(i);
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (auto j:graph[i])
            adj[j].push_back(i);
        }
        int node;
        while (!q.empty()) {
            node = q.front();
            // cout<<node<<endl;
            ans.push_back(node);
            q.pop();
            for (auto i:adj[node]) {
                outdegree[i]--;
                if (outdegree[i] == 0)
                q.push(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};