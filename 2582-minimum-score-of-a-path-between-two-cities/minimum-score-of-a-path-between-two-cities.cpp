class Solution {
public:
    void dfs(vector<vector<pair<int,int>>> &adj,int node,vector<bool> &visted){
        if(visted[node])
        return;
        visted[node]=true;
        for(auto i:adj[node]){
            dfs(adj,i.first,visted);
        }
        return;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        int ans=INT_MAX;
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<bool> visted(n,false);
        dfs(adj,1,visted);
        for(int i=0;i<=n;i++){
            if(visted[i]){
                // cout<<i<<" ";
                for(auto j:adj[i]){
                    ans=min(ans,j.second);
                }
            }
        }
        return ans;
    }
};