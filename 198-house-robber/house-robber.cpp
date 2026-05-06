class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size(),c;
        if(n==1)
        return nums[0];
        int a=nums[0],b=max(nums[0],nums[1]);;
        if(n==2)
        return b;
        for(int i=2;i<n;i++){
            c=max(a+nums[i],b);
            a=b;
            b=c;
        }
        return c;
    }
};