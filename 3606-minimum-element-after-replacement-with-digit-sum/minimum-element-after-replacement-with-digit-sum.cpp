class Solution {
public:
    int minElement(vector<int>& nums) {
        int s=0,r,n,ans=INT_MAX;
        for(auto i:nums){
            n=i;
            s=0;
            while(n>0){
                r=n%10;
                s+=r;
                n=n/10;
            }
            ans=min(ans,s);
        }
        return ans;
    }
};