class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int r,c,s,ans=0,n=grid.size(),m=grid[0].size(),one=0;
        vector<vector<bool>> visted(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                one=1;
            }
        }
        if(q.size()==0&&one==0)
        return 0;
        if(q.size()==0&&one==1)
        return -1;
        while(!q.empty()){
            s=q.size();
            if(s==0)
            break;
            ans++;
            for(int i=0;i<s;i++){
                r=q.front().first; 
                c=q.front().second;
                grid[r][c]=2;
                if(r+1<n&&!visted[r+1][c]&&grid[r+1][c]==1)
                {
                    q.push({r+1,c}); 
                    visted[r+1][c]=true;
                }
                if(r-1>=0&&!visted[r-1][c]&&grid[r-1][c]==1)
                {
                    q.push({r-1,c}); 
                    visted[r-1][c]=true;
                }
                if(c+1<m&&!visted[r][c+1]&&grid[r][c+1]==1)
                {
                    q.push({r,c+1}); 
                    visted[r][c+1]=true;
                }
                if(c-1>=0&&!visted[r][c-1]&&grid[r][c-1]==1)
                {
                    q.push({r,c-1}); 
                    visted[r][c-1]=true;
                }
                q.pop();
            }               
        }
        for(auto i:grid){
            for(auto j:i){
                if(j==1)
                return -1;
            }
        }
        return ans-1;
    }
};