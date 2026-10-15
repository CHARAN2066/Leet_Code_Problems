class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), a = 0, b = 0, c = n - 1;
        while (a <= b && b <= c) {
            if (nums[b] == 1) {
                b++;
                continue;
            }
            else if (nums[b] == 0) {
                swap(nums[b], nums[a]);
                a++;
                b++;
            }
            else {
                swap(nums[b], nums[c]);
                c--;
                // b++;
            }
        }
    }
};