class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int s=0;
        vector<int> ans;
        for(auto i:nums)
        {
            s+=i;
            ans.push_back(s);
        }
        return ans;
    }
};