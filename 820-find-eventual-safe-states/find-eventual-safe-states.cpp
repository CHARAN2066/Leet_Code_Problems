class Solution {
public:
    map<int, int> mp;
    bool dfs(vector<vector<int>>& graph, int curr, vector<bool>& visted) {
        if (mp[curr] == 1)
        return true;
        if (visted[curr])
        return false;
        visted[curr] = true;
        bool a = true;
        for (auto i:graph[curr]) {
            // if (i == curr)
            // continue;
            // if (curr == 3)
            // cout<<i<<endl;
            a = a & dfs(graph, i, visted);
        }
        if (a) {
            mp[curr] = 1;
        }
        // visted[curr] = false;
        return a;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<bool> visted(n, false);
        for (int i = 0; i < n; i++) {
            if (mp[i] == 1)
            {
                // cout<<"s";
                continue;
            }
            // cout<<i<<endl;
            dfs(graph, i, visted);
        }
        for (auto i:mp) {
            if (i.second == 1) {
                ans.push_back(i.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};