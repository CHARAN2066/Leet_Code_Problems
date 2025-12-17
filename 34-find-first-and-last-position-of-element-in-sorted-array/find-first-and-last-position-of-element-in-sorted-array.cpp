class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        long long int low=0,high=n-1,mid;
        int a1=-1,a2=-1;
        while(low<=high){
            mid=high-(high-low)/2;
            if(nums[mid]==target)
            {
                a1=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        low=0,high=n-1;
        while(low<=high){
            mid=high-(high-low)/2;
            if(nums[mid]==target)
            {
                a2=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return {a1,a2};
        
    }
};