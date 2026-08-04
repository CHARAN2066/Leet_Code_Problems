class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(),curr=0,ans=INT_MIN;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            ans=max(curr,ans);
            if(curr<0)
            curr=0;
        }
        return ans;        
    }
};