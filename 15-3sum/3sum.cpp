class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int a, b;
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            a = 0;
            b = n - 1;
            while (a < b) {
                if (nums[a] + nums[b] == -(nums[i])) {
                    if (a != b && b != i && i != a) {
                        temp.clear();
                        temp.push_back(nums[a]);
                        temp.push_back(nums[b]);
                        temp.push_back(nums[i]);
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                    a++;
                    b--;
                }
                else if (nums[a] + nums[b] < -(nums[i])) {
                    a++;
                }
                else {
                    b--;
                }
            }
        }

        vector<vector<int>> res;
        for (auto i:ans) {
            res.push_back(i);
        }
        return res;
    }
};