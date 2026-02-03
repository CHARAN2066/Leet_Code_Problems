class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size(),a=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>=nums[i+1]){
                a=i;
                break;
            }
        }
        if(a==-1||a==0)
        return false;
        int b=-1;
        for(int i=a;i<n-1;i++){
            if(nums[i]<=nums[i+1]){
                b=i;
                break;
            }
        }
        if(b==-1)
        return false;
        for(int i=b;i<n-1;i++){
            if(nums[i]>=nums[i+1])
            return false;
        }
        return true;
    }
};