class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<int> temp;
        int n=grid.size();
        int a,b,k,m=grid[0].size();
        for(int i=1;i<n;i++)
        {
            a=0,b=i;
            while(a<n&&b<m)
            {
                temp.push_back(grid[a][b]);
                a++;
                b++;
            }
            sort(temp.begin(),temp.end());
            a=0,b=i;
            k=0;
            while(a<n&&b<m)
            {
                grid[a][b]=temp[k];
                a++;
                b++;
                k++;
            }
            temp.clear();
            // break;
        }
        temp.clear();
        for(int i=0;i<m;i++)
        {
            a=i,b=0;
            while(a<n&&b<m)
            {
                temp.push_back(grid[a][b]);
                a++;
                b++;
            }
            sort(temp.begin(),temp.end(),greater<int>());
            a=i,b=0;
            k=0;
            while(a<n&&b<m)
            {
                grid[a][b]=temp[k];
                a++;
                b++;
                k++;
            }
            temp.clear();
            // break;
        }
        return grid;
    }
};