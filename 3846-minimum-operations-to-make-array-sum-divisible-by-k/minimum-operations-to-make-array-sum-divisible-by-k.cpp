class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int s=0;
        for(auto i:nums)
        s+=i;
        return s%k;
        
    }
};