class Solution {
public:
    map<string, bool> isThere;
    double bfs(map<string, vector<pair<string, double>>> &adj, map<string, bool> &visted, string src, string des ) {
        double pr = 1, path;
        string temp;
        if (!isThere[src] || !isThere[des])
        return -1;
        if (src == des)
        return pr;
        queue<pair<string, double>> q;
        q.push({src, 1});
        while (!q.empty()) {
            temp = q.front().first;
            path = q.front().second;
            // cout<<path<<endl;
            q.pop();
            if (temp == des) {
                return path;
            }
            visted[temp] = true;
            // cout<<endl<<temp<<endl;
            for (auto i:adj[temp]) {
                // cout<<i.first<<" ";
                if (!visted[i.first]) {
                    // cout<<temp<<" "<<i.first<<endl;
                    q.push({i.first, path * i.second});
                }
            }
        }
        return -1;
    }
     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> adj;
        // map<string, bool> isThere;
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            isThere[equations[i][0]] = true;
            isThere[equations[i][1]] = true;
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], (static_cast<double>(1) / values[i])});
        }
        // cout<<adj.find("a");
        vector<double> ans;
        // for (auto i:adj["b"])
        // cout<<i.first<<" "<<i.second<<endl;
        double res;
        for (auto i:queries) {
            map<string, bool> visted;
            res = bfs(adj, visted, i[0], i[1]);
            ans.push_back(res);
        }
        return ans;
    }
};