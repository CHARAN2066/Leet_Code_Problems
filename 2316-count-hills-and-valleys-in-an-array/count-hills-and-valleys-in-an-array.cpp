class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size(), a, b, ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == nums[i - 1])
            continue;
            a = i;
            while (a >= 0 &&nums[a] == nums[i]) {
                a--;
            }
            if (a < 0)
            continue;
            b = i;
            while (b < n && nums[b] == nums[i]) {
                b++;
            }
            if (b >= n)
            continue;
            if ((nums[a] < nums[i] && nums[b] < nums[i]) || (nums[a] > nums[i] && nums[b] > nums[i]))
            {
                cout<<i<<endl;
                ans++;
            }
        }
        return ans;
    }
};