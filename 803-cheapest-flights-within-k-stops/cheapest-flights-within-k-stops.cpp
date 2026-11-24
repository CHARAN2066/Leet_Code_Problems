class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int, int>> pq;
        vector<vector<pair<int, int>>> adj(n + 1);
        vector<int> dis(n + 1, INT_MAX);
        dis[src] = 0;
        for (auto i:flights) {
            adj[i[0]].push_back({i[1], i[2]});
            // adj[i[1]].push_back({i[0], i[2]});
        }
        pq.push({0, src});
        int node, d, level = 0, s;
        while (!pq.empty()) {
            s = pq.size();
            if (level == k + 1)
            break;
            for (int l = 0; l < s; l++) {
                d = pq.front().first;
                node = pq.front().second;
                // ans++;
                pq.pop();
                for (auto i:adj[node]) {
                    if (dis[i.first] > d + i.second) {
                        dis[i.first] = d + i.second;
                        pq.push({dis[i.first], i.first});
                    }
                }
            }
            // for (int i = 0; i <= n; i++)
            // cout<< dis[i]<< " ";
            // cout<< endl;
            level++;
        }
        // if (ans > k) {
        //     return -1;
        // }
        // cout<< ans<<endl;
        if (dis[dst] == INT_MAX)
        return -1;
        return dis[dst];
    }
};