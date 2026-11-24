class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long int, long long int>>> adj(n);
        for (auto i:roads) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
        long long int node, d;
        long long int MOD = 1e9 + 7;
        vector<long long int> dis(n, LLONG_MAX);
        dis[0] = 0;
        pq.push({0, 0});
        vector<long long int> paths(n, 1);
        while (!pq.empty()) {
            d = pq.top().first;
            node = pq.top().second;
            pq.pop();
            for (auto i:adj[node]) {
                if (dis[i.first] > (d + i.second)) {
                    dis[i.first] = d + i.second;
                    paths[i.first] = paths[node];
                    pq.push({dis[i.first], i.first});
                }
                else if (dis[i.first] == d + i.second) {
                    paths[i.first] = (paths[i.first] + paths[node]) % MOD;
                }
            }
        }
        return paths[n - 1];
    }
};