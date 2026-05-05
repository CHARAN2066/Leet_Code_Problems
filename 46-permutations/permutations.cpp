class Solution {
public:
    vector<vector<int>> ans;
    
    int t;
    void fun(int i,int n,vector<int> &nums,vector<int> &temp){
        // cout<<i<<endl;
        if(i==n-1){
            // cout<<"s";
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<n;j++){
            t=nums[i];
            nums[i]=nums[j];
            nums[j]=t;
            fun(i+1,n,nums,temp);
            t=nums[i];
            nums[i]=nums[j];
            nums[j]=t;
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        int n=nums.size();
        fun(0,n,nums,temp);
        return ans;
    }
};