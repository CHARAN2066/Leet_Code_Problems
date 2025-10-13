class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        queue<int> q;
        vector<int> indegree(n);
        vector<int> ans;
        vector<vector<int>> adj(n);
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
        }
        for(auto i:edges)
        {
            indegree[i[1]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        int t;
        while(!q.empty())
        {
            t=q.front();
            ans.push_back(t);
            for(auto i:adj[t])
            {
                indegree[i]--;
                if(indegree[i]==0)
                q.push(i);
            }
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()!=n)
        return {};
        else
        return ans;
    }
};