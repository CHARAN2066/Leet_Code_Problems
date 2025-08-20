class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int a=max(m,n),ans=0;
        vector<vector<int>> row_prefix(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j==0)
                row_prefix[i][j]=matrix[i][j];
                else
                row_prefix[i][j]=matrix[i][j]+row_prefix[i][j-1];
            }
        }
        vector<vector<int>> prefix(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0&&j==0)
                prefix[i][j]=matrix[i][j];
                else if(i==0)
                prefix[i][j]=row_prefix[i][j-1]+matrix[i][j];
                else if(j==0)
                prefix[i][j]=prefix[i-1][j]+matrix[i][j];
                else
                prefix[i][j]=row_prefix[i][j-1]+prefix[i-1][j]+matrix[i][j];
            }
        }
        int l1,r1,l2,r2,ones;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<m;k++)
                {
                    l1=j;
                    r1=k;
                    l2=j+i;
                    r2=k+i;
                    if(l1>=n||l2>=n||r1>=m||r2>=m)
                    continue;
                    if(l1==0&&r1==0)
                    ones=prefix[l2][r2];
                    else if(l1==0)
                    ones=prefix[l2][r2]-prefix[l2][r1-1];
                    else if(r1==0)
                    ones=prefix[l2][r2]-prefix[l1-1][r2];
                    else
                    ones=prefix[l2][r2]-prefix[l1-1][r2]-prefix[l2][r1-1]+prefix[l1-1][r1-1];
                    if(ones==(i+1)*(i+1))
                    ans++;
                }
            }
        }
        return ans;
        
    }
};