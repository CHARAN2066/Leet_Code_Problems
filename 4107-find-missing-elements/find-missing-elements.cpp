class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size(), a = nums[0], i = 1;
        while (i < n) {
            a++;
            if (a > nums[n - 1])
            break;
            // cout<< a<< endl;
            if (nums[i] != a)
            ans.push_back(a);
            else 
            i++;
        }
        return ans;
    }
};