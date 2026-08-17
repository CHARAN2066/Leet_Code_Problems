class Solution {
public:
    void dfs(vector<vector<int>> &adj,int node,vector<bool> &visted)
    {
        if(visted[node])
        return;
        visted[node]=true;
        for(auto i:adj[node])
        {
            if(!(visted[i]))
            dfs(adj,i,visted);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int ans=0;
        int s=connections.size();
        if((n-1)>s)
        return -1;
        vector<bool> visted(n,false);
        vector<vector<int>> adj(n);
        for(auto i:connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!(visted[i]))
            {
                ans++;
                dfs(adj,i,visted);
            }
        }
        return ans-1;
    }
};