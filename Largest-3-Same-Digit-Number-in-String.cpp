class Solution {
public:
    string largestGoodInteger(string num) {
        int ans=-1,n=num.size();
        for(int i=0;i<n-2;i++)
        {
            if((num[i]==num[i+1])&&(num[i+1]==num[i+2]))
            {
                ans=max(ans,(num[i]-'0'));
            }
        }
        cout<<ans<<endl;
        if(ans==-1)
        {
            return "";
        }
        // string res=(ans+'0')+(ans+'0')+(ans+'0');
        return to_string(ans)+to_string(ans)+to_string(ans);
    }
};