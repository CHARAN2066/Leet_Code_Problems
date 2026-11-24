class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto i:times) {
            adj[i[0]].push_back({i[1], i[2]});
        }
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int node, d;
        pq.push({0, k});
        while (!pq.empty()) {
            d = pq.top().first;
            node = pq.top().second;
            pq.pop();
            for (auto i:adj[node])
            {
                if (dis[i.first] > (d + i.second)) {
                    dis[i.first] = d + i.second;
                    pq.push({dis[i.first], i.first});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < dis.size(); i++) {
            cout<<dis[i]<<" ";
            if (dis[i] == INT_MAX)
            return -1;
            ans = max(ans, dis[i]);
        }
        return ans;
    }
};