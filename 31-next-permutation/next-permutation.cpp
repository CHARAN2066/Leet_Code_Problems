class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int a = -1, b = -1, n = nums.size();
        if (n == 1)
        return;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                a = i;
                break;
            }
        }
        if (a == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[a]) {
                b = i;
                break;
            }
        }
        swap(nums[a], nums[b]);
        reverse(nums.begin() + a + 1, nums.end());
        return;
    }
};