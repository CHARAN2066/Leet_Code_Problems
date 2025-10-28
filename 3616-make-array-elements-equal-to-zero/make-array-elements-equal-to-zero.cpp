class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int s=0,ans=0;
        int n=nums.size();
        for(auto i:nums)
        s+=i;
        int l=0,t=0;
        for(auto i:nums)
        {
            t+=i;
            if(((s-t)==t)&&(i==0))
            {
                // cout<<i<<endl;
                ans++;
            }
            else if((abs((s-t)-t)==1)&&(i==0))
            l++;
        }
        return ans*2+l;
        
    }
};