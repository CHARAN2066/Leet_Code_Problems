class Solution {
public:
    vector<vector<int>> p;
    void helper(vector<vector<int>> &heights,int i,int j,int n,int m,int flag){
        if(i>=n||j>=m||i<0||j<0)
        return;
        if(flag==1){
            if(p[i][j]==1)
            return;
            p[i][j]=1;
        }
        else{
            if(p[i][j]>1)
            return;
            p[i][j]+=2;
        }
        if((i+1<n)&&(heights[i+1][j]>=heights[i][j]))
        helper(heights,i+1,j,n,m,flag);
        if((j+1<m)&&(heights[i][j+1]>=heights[i][j]))
        helper(heights,i,j+1,n,m,flag);
        if((i-1>=0)&&(heights[i-1][j]>=heights[i][j]))
        helper(heights,i-1,j,n,m,flag);
        if((j-1>=0)&&(heights[i][j-1]>=heights[i][j]))
        helper(heights,i,j-1,n,m,flag);
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        p.resize(n,vector<int>(m,0));
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            helper(heights,i,0,n,m,1);
        }
        for(int i=0;i<m;i++){
            helper(heights,0,i,n,m,1);
        } 
        for(int i=0;i<n;i++){
            helper(heights,i,m-1,n,m,2);
        }
        for(int i=0;i<m;i++){
            helper(heights,n-1,i,n,m,2);
        }     
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[i][j]==1||p[i][j]%2==0)
                continue;
                ans.push_back({i,j});
            }
        }   
        return ans;
    }
};