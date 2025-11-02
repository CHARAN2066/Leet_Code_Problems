class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> matrix(m,vector<int> (n,0));
        for(auto i:walls)
        {
            matrix[i[0]][i[1]]=2;
        }
        for(auto i:guards)
        {
            matrix[i[0]][i[1]]=3;
        }
        int a,b;
        for(auto i:guards)
        {
            a=i[0];
            b=i[1];
            for(int j=b+1;j<n;j++)
            {
                if((matrix[a][j]==2)||(matrix[a][j]==3))
                break;
                else
                matrix[a][j]=1;
            }
            for(int k=b-1;k>=0;k--)
            {
                if((matrix[a][k]==2)||(matrix[a][k]==3))
                break;
                else
                matrix[a][k]=1;
            }
            for(int l=a+1;l<m;l++)
            {
                if((matrix[l][b]==2)||(matrix[l][b]==3))
                break;
                else
                matrix[l][b]=1;
            }
            for(int f=a-1;f>=0;f--)
            {
                if((matrix[f][b]==2)||(matrix[f][b]==3))
                break;
                else
                matrix[f][b]=1;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    // cout<<i<<" "<<j<<endl;
                    ans++;
                }
            }
        }
        return ans;
        
    }
};