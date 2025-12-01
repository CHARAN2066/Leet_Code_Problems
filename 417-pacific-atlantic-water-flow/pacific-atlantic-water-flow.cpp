class Solution {
public:
    void fun(vector<vector<int>>& heights,int i,int j,int n,int m,vector<vector<int>>& visted,bool &pa,bool &at){
        if(i>=n||j>=m||i<0||j<0)
        return;
        if(visted[i][j]==1)
        return;
        visted[i][j]=1;
        if(i==0||j==0)
        pa=true;
        if(i==n-1||j==m-1)
        at=true;
        // cout<<"1";
        if((i+1<n)&&(heights[i+1][j]<=heights[i][j]))
        fun(heights,i+1,j,n,m,visted,pa,at);
        if((j+1<m)&&(heights[i][j+1]<=heights[i][j]))
        fun(heights,i,j+1,n,m,visted,pa,at);
        if((i-1>=0)&&(heights[i-1][j]<=heights[i][j]))
        fun(heights,i-1,j,n,m,visted,pa,at);
        if((j-1>=0)&&(heights[i][j-1]<=heights[i][j]))
        fun(heights,i,j-1,n,m,visted,pa,at);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n=heights.size();
        int m=heights[0].size();
        bool pa=false;
        bool at=false;
        vector<vector<int>> visted(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                pa=false;
                at=false;
                visted.assign(n,vector<int> (m,0));
                fun(heights,i,j,n,m,visted,pa,at);
                // cout<<pa<<" "<<at<<endl;
                if(pa==true&&at==true)
                ans.push_back({i,j});
                // cout<<endl;
            }
        }
        return ans;
    }
};