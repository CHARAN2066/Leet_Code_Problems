class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1,mid;
        int ans=INT_MAX;
        while(low<=high){
            mid=(low+high)/2;
            ans=min(ans,nums[mid]);
            if((nums[mid]<=nums[high])&&(nums[low]<=nums[mid]))
            {
                high=mid-1;
            }
            else if(nums[low]<=nums[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};