class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size(),f=-1,l=-1,low=0,high=n-1,mid;
        if(n==1)
        return nums[0];
        while(low<=high){
            mid=(low+high)/2;
            // cout<<mid<<endl;
            if(mid!=0&&mid!=n-1&&nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1])
            return nums[mid];
            else if(mid==n-1&&nums[mid]!=nums[mid-1])
            return nums[mid];
            else if(mid==0&&nums[mid]!=nums[mid+1])
            return nums[mid];
            if(mid%2!=0){
                if(mid!=0&&nums[mid]!=nums[mid-1]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(mid!=0&&nums[mid]==nums[mid-1]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
        return -1;
    }
};