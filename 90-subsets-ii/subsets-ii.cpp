class Solution {
public:
    vector<vector<int>> ans;
    map<vector<int>,int> mp;
    vector<int> temp2;
    void fun(int i,int n,vector<int> &nums,vector<int> &temp){
        if(i>=n){
            temp2.clear();
            temp2.insert(temp2.begin(),temp.begin(),temp.end());
            sort(temp2.begin(),temp2.end());
            if(mp[temp2]!=1)
            {
                ans.push_back(temp2);
                mp[temp2]=1;
            }
            return;
        }
        fun(i+1,n,nums,temp);
        temp.push_back(nums[i]);
        fun(i+1,n,nums,temp);
        temp.pop_back();
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        fun(0,n,nums,temp);
        return ans;  
    }
};
