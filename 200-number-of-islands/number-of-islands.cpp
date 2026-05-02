class Solution {
public:
    void helper(vector<vector<char>> &grid,int i,int j,int n,int m){
        if(i==n||j==m||i<0||j<0)
        return ;
        if(grid[i][j]=='*'||grid[i][j]=='0')
        return;
        grid[i][j]='*';
        helper(grid,i+1,j,n,m);
        helper(grid,i,j+1,n,m);
        helper(grid,i-1,j,n,m);
        helper(grid,i,j-1,n,m);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1')
                {
                    ans++;
                    helper(grid,i,j,n,m);
                }
            }
        }
        return ans;
        
    }
};