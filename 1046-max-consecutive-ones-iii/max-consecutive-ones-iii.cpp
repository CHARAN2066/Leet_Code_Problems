class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int c=0,l=0,ans=0;
        int n=nums.size();
        for(int end=0;end<n;end++){
            if(nums[end]==0)
            c++;
            while(c>k){
                if(nums[l]==0)
                c--;
                l++;
            }
            ans=max(ans,end-l+1);
        }
        return ans;
    }
};