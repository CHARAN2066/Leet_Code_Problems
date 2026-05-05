class Solution {
public:
    vector<vector<int>> ans;
    void fun(vector<int> &candidates,vector<int> &temp,int target,int curr,int i,int n){
        if(curr>target){
            // if(temp.size()>=1)
            // temp.pop_back();
            return;
        }
        if(curr==target){
            // cout<<"s";
            ans.push_back(temp);
            return;
        }
        if(i>=n)
        return;
        // cout<<i<<endl;
        // for(auto k:temp)
        // cout<<k<<" ";
        // cout<<endl;
        temp.push_back(candidates[i]);
        fun(candidates,temp,target,curr+candidates[i],i,n);
        if(temp.size()>=1)
        temp.pop_back();
        fun(candidates,temp,target,curr,i+1,n);
        // if(temp.size()>=1)
        // temp.pop_back();
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> temp;
        fun(candidates,temp,target,0,0,n);
        return ans;
    }
};