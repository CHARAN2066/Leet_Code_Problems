class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto i:prerequisites) {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
            q.push(i);
        }
        int a;
        vector<int> ans;
        while (!q.empty()) {
            a = q.front();
            q.pop();
            ans.push_back(a);
            for (auto i:adj[a]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }
        if (ans.size() == n)
        return true;
        return false;
    }
};