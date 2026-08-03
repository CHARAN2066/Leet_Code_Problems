class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0, n = nums.size(); 
        while (i < n) {
            if (nums[i] == i + 1) 
            {
                i++;
                continue;
            }
            else {
                if (nums[nums[i] - 1] ==  nums[i])
                return nums[i];
                swap(nums[i], nums[nums[i] - 1]);
            }
            // for (auto i:nums) {
            //     cout<< i<< " ";
            // }
            // cout<< endl;
        }
        return 0;
    }
};