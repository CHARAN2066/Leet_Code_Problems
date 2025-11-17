class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size();
        int p=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1)
            {
                if(p!=-1)
                {
                    // cout<<i<<" "<<p<<endl;
                    if((i-p-1)<k)
                    return false;
                }
                p=i;
            }
        }
        return true;
        
    }
};