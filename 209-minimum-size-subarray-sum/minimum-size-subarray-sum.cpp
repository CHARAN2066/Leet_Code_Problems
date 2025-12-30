class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=0,low=0,res=INT_MAX;
        int n=nums.size();
        for(int end=0;end<n;end++){
            ans+=nums[end];
            if(ans>=target)
            res=min(res,(end-low+1));
            while(ans>=target){
                ans-=nums[low];
                low++;
                if(ans>=target)
                res=min(res,(end-low+1));
            }
        }
        if(res==INT_MAX)
        return 0;
        return res;
    }
};