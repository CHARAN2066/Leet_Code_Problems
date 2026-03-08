class Solution {
public:
    int to_number(string s)
    {
        int ans=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            ans+=(s[i]-'0')*pow(2,n-i-1);
        }
        return ans;
    }
    string to_binary(int n)
    {
        int r;
        string ans;
        while(n>0)
        {
            r=n%2;
            ans.push_back(static_cast<char>(r+'0'));
            n=n/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        int s=pow(2,n);
        vector<int> fre(s,0);
        for(int i=0;i<n;i++)
        {
            fre[to_number(nums[i])]++;
        }
        string ans;
        for(int i=0;i<s;i++)
        {
            if(fre[i]==0)
            {
                // cout<<i<<" ";
                ans=to_binary(i);
                break;
            }
        }
        // cout<<ans<<endl;
        while(ans.size()<n)
        {
            ans.insert(ans.begin(),'0');
        }
        return ans;
    }
};