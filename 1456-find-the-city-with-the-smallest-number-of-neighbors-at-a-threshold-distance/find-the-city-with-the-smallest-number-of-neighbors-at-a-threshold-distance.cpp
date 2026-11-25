class Solution {
public:
    void disjkra(vector<int> &dis, vector<vector<pair<int, int>>> &adj, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        int d, node;
        while (!pq.empty()) {
            d = pq.top().first;
            node = pq.top().second;
            pq.pop();
            for (auto j:adj[node]) {
                if (dis[j.first] > d + j.second) {
                    dis[j.first] = d + j.second;
                    pq.push({dis[j.first], j.first});
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto i:edges) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        vector<int> dis(n, INT_MAX);
        vector<int> cities(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis[j] = INT_MAX;
            }
            dis[i] = 0;
            count = 0;
            disjkra(dis, adj, i);
            for (int j = 0; j < n; j++) {
                if (dis[j] == 0)
                continue;
                if (dis[j] <= distanceThreshold) {
                    count++;
                }
            }
            cities[i] = count;
        }
        int mi = INT_MAX, ans;
        for (int i = 0; i < n; i++) {
            if (cities[i] <= mi) {
                mi = cities[i];
                ans = i;
            }
        }
        return ans;
    }
};