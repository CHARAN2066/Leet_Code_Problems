class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) 
    {
        int n=grid.size(),r=0;
        int a=grid[0].size();
         int mir=n,mic=a,mar=-1,mac=-1,flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<a;j++)
            {
                if(grid[i][j]==1)
                {
                    mir=min(mir,i);
                    mar=max(mar,i);
                    mic=min(mic,j);
                    mac=max(mac,j);
                }
            } 
        }
        if(mar==-1||mac==-1||mir==n||mic==a)
            return 0;
        else
        return (mar-mir+1)*(mac-mic+1);
    }
};