class Solution {
public:
    int minCost(string c, vector<int>& a) {
        int n=c.size();
        int s=0;
        int m=0;
        int ans=0;
        s=a[0];
        m=a[0];
        for(int i=0;i<n-1;i++)
        {
            if(c[i]==c[i+1])
            {
                s+=a[i+1];
                m=max(m,a[i+1]);
            }
            else{
                // cout<<s<<" "<<m<<endl;
                ans+=(s-m);
                s=a[i+1];
                m=a[i+1];
            }
        }
        ans+=(s-m);
        return ans;
    }
};