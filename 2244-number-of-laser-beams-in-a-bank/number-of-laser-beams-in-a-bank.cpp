class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int m=bank[0].size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(bank[i][j]=='1')
                ans[i]++;
            }
        }
        // for(auto i:ans)
        // cout<<i<<" ";
        // cout<<endl;
        int res=0,t=-1;
        for(int i=0;i<n;i++)
        {
            if(ans[i]==0)
            continue;
            if(t==-1)
            t=ans[i];
            else
            {
                res+=(t*ans[i]);
                t=ans[i];
            }
        }
        return res;
        
    }
};