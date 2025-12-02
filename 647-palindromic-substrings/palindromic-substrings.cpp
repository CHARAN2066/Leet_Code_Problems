class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool> (n,false));
        for(int i=0;i<n;i++)
        dp[i][i]=true;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            dp[i][i+1]=true;
        }
        int i=0,j=2,l=2;;
        while(true){
            if(j>=n||i>=n)
            {
                l++;
                if(l>n)
                break;
                i=0;
                j=l;
            }
            // cout<<i<<" "<<j<<endl;
            if((s[i]==s[j])&&(dp[i+1][j-1]))
            {
                // cout<<i<<" "<<j<<endl;
                dp[i][j]=true;
            }
            i++;
            j++;
        }
        int c=0;
        for(auto i:dp)
        {
            for(auto j:i)
            {
                // cout<<j<<" ";
                if(j==1)
                c++;
            }
            // cout<<endl;
        }
        return c;

        
    }
};