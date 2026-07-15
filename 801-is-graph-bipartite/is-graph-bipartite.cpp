class Solution {
public:
    bool helper(vector<vector<int>>& graph, vector<int> &colors, int start) {
        queue<int> q;
        int node;
        q.push(start);
        colors[start] = 0;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            for (auto i:graph[node]) {
                if (colors[i] == -1)
                {
                    colors[i] = !colors[node];
                    q.push(i);
                }
                if (colors[i] == colors[node])
                return 0;
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        int n = graph.size(), node, ans = true;;
        vector<int> colors(n, -1);
        for (int i = 0; i < n; i++) {
            if (colors[i] == -1)
            ans = ans & helper(graph, colors, i);
        }
        return ans;
    }
};