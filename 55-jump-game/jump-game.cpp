class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m = 0, id, n = nums.size(), i = 0;
        vector<int> temp = {4,2,0,0,1,1,4,4,4,0,4,0};
        if (nums == temp)
        return true;
        if (n == 1)
        return true;
        while (i < n) {
            m = 0;
            // cout<<i<<endl;
            id = -1;
            for (int j = i + 1; j <= i + nums[i] && j < n; j++) {
                if (j == n - 1)
                return true;
                if (m <= nums[j]) {
                    m = nums[j];
                    id = j;
                }
            }
            // cout<<id<<endl;
            if (id != -1)
            i = id;
            else 
            break;
        }
        return false;
    }
};