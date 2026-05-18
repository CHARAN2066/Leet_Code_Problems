class Solution {
public:
    void helper(int n,vector<int> &visted,vector<vector<int>> &adj){
        if(visted[n]==1)
        return;
        visted[n]=1;
        for(auto i:adj[n]){
            helper(i,visted,adj);
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& edges) {
        int n=edges.size(),ans=0;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
                if(edges[i][j]==1)
                adj[i].push_back(j);
           }
        }
        vector<int> visted(n,0);
        for(int i=0;i<n;i++){
            if(visted[i]==0){
                ans++;
                helper(i,visted,adj);
            }
        }
        return ans;
    }
};