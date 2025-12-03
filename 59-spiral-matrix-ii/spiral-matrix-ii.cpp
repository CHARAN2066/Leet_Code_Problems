class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>> ans(n,vector<int>(n,0));
       int t=0,c=1;
       while(true){
            
            for(int i=t;i<n-t;i++)
            {
                // if(ans[t][i]!=0)
                // break;
                ans[t][i]=c;
                c++;
            }
            
            for(int i=t+1;i<n-t;i++)
            {
                // if(ans[i][n-1-t]!=0)
                // break;
                ans[i][n-1-t]=c;
                c++;
            }
            
            for(int i=n-t-2;i>=t;i--)
            {
                // if(ans[n-1-t][i]!=0)
                // break;
                ans[n-1-t][i]=c;
                c++;
            }
            // break;
            for(int i=n-t-2;i>t;i--)
            {
                // if(ans[i][t]!=0)
                // break;
                ans[i][t]=c;
                c++;
            }
            if(c>n*n)
            break;
            t++;
       }
       return ans;
    }
};