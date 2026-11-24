class Solution {
public:
    int lcm(int a, int b) 
    {
    return (a/gcd(a,b))*b;
    }
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        long long int g=nums[0],l=nums[0];
        long long int pr=nums[0];
        int ans=0;
        // cout<<gcd(1,2)<<endl;
        for(int i=0;i<n;i++)
        {
            g=nums[i],l=nums[i],pr=nums[i];
            for(int j=i+1;j<n;j++)
            {
                g=gcd(g,nums[j]);
                l=lcm(l,nums[j]);
                // cout<<g<<" "<<l<<" "<<pr;
                if(pr>LLONG_MAX/nums[j]) 
                break;
                pr*=nums[j];
                if(pr==(g*l))
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};