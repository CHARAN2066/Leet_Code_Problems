class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
       int a = 0, b = 0;
       for (auto i:nums) {
            if (i < target)
            a++;
            if (i == target)
            b++;
       }
    //    cout<<a<<" "<<b<<endl;
       vector<int> ans;
       for (int i = 1; i <= b; i++)
       ans.push_back(i + a - 1);
       return ans;
    }
};