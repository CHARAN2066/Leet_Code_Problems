class Solution {
public:
    int helper(vector<vector<int>> &grid,int i,int j,int n,int m){
        if(i>=n||j>=m||i<0||j<0)
        return 0;
        if(grid[i][j]==-1||grid[i][j]==0)
        return 0;
        int ans=0;
        grid[i][j]=-1;
        ans+=helper(grid,i+1,j,n,m);
        ans+=helper(grid,i,j+1,n,m);
        ans+=helper(grid,i-1,j,n,m);
        ans+=helper(grid,i,j-1,n,m);
        return 1+ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0,a;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    a=helper(grid,i,j,n,m);
                    // cout<<i<<" "<<j<<" "<<a<<endl;
                    ans=max(ans,a);
                }
            }
        }
        return ans;
    }
};