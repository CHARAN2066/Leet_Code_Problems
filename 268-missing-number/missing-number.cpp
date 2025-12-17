class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s=0;
        for(auto i:nums){
            s+=i;
        }
        int n=nums.size();
        int a=(n*(n+1))/2;
        return a-s;
        
    }
};