class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int l=0,n=nums.size(),s=0,r;
        vector<int> ans;
        for(auto i:nums) s+=i;
        for(int i=0;i<n;i++){
            r=(s-l-nums[i]);
            ans.push_back(abs(l-r));
            l+=nums[i];
        }
        return ans;
        
    }
};