class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int ans=1,res=0;
        for(int i=0;i<n;i++) 
        dp[i][i]=true;
        if(n<2)
        return s.substr(0,1);
        for(int i=0;i<n-1;i++){
            if(ans==1&&s[i]==s[i+1]){
                res=i;
            }
            if(s[i]==s[i+1])
            {
                ans=2;
                dp[i][i+1]=true;
            }
        }
        // cout<<dp[1][2]<<endl;
        if(n<3)
        return s.substr(res,ans);
        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                // cout<<s[i]<<" "<<s[i+len-1]<<endl;
                if(s[i]==s[i+len-1]&&dp[i+1][i+len-2])
                {
                    dp[i][i+len-1]=true;
                    if(ans<len){
                        res=i;
                        ans=len;
                    }
                }
            }
        }
        // cout<<ans<<endl;
        return s.substr(res,ans);
    }
};