class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int e = 0, o = 1, n = nums.size();
        while (e < n && o < n) {
            if (nums[e] % 2 != 0) {
                swap(nums[e], nums[o]);
                o += 2;
            }
            else {
                e += 2;
            }
        }
        return nums;
    }
};