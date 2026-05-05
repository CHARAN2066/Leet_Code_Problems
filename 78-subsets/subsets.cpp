class Solution {
public:
    vector<vector<int>> ans;
    void fun(int i,int n,vector<int> &nums,vector<int> &temp){
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        fun(i+1,n,nums,temp);
        temp.push_back(nums[i]);
        fun(i+1,n,nums,temp);
        temp.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        fun(0,n,nums,temp);
        return ans;
    }
};