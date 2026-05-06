class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int m=box[0].size();
        vector<vector<char>> ans(m,vector<char> (n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            ans[j][n-1-i]=box[i][j];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(ans[j][i]=='.')
                {
                    for(int k=j-1;k>=0;k--)
                    {
                        if(ans[k][i]=='*')
                        break;
                        else if(ans[k][i]=='#')
                        {
                            ans[j][i]='#';
                            ans[k][i]='.';
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};