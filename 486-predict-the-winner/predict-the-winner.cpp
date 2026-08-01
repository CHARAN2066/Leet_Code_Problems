class Solution {
public:
    bool helper(vector<int>& nums, int f, int l, bool flag, int i, int n, int p1, int p2) {
        if (i == n) {
            // cout<< p1<< " "<< p2<< endl;
            if (p1 >= p2)
            return true;
            return false;
        }
        bool a, b;
        if (flag) {
            a = helper(nums, f + 1, l, !flag, i + 1, n, p1 + nums[f], p2);
            b = helper(nums, f, l - 1, !flag, i + 1, n, p1 + nums[l], p2);
            return a || b;
        }
        else {
            a = helper(nums, f + 1, l, !flag, i + 1, n, p1, p2 + nums[f]);
            b = helper(nums, f, l - 1, !flag, i + 1, n, p1, p2 + nums[l]);
            return a && b;
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size(), f = 0, l = n - 1, p1 = 0, p2 = 0;
        return helper(nums, 0, n - 1, true, 0, n, p1, p2);
    }
};