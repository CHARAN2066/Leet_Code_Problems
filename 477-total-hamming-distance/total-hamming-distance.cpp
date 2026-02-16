class Solution {
public:
    int fun(int a,int b){
        int c=a^b,ans=0;
       return __builtin_popcount(c);
    }
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans+=fun(nums[i],nums[j]);
            }
        }
        return ans;
    }
};