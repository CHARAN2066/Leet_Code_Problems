class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int, vector<int>>> q;
        vector<int> temp;
        temp.push_back(0);
        vector<bool> visted(n, false);
        int node;
        vector<vector<int>> ans;
        q.push({0, temp});
        while (!q.empty()) {
            node = q.front().first;
            temp = q.front().second;
            q.pop();
            if (node == n - 1) {
                ans.push_back(temp);
            }
            if (visted[node])
            continue;
            // visted[node] = true;
            // cout<<node<<"->";
            for (auto j:graph[node]) {
                // cout<<j<<" ";
                temp.push_back(j);
                q.push({j, temp});
                temp.pop_back();
            }
            cout<<endl;
        }
        return ans;
    }
};