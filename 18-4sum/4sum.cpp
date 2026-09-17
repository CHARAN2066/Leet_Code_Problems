class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        set<vector<int>> st;
        long long int a, n = nums.size(), k, l, b;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // cout<<i<<" "<<j<< endl;
                a = nums[i] + nums[j];
                k = 0, l = n - 1;
                while (k < l) {
                    while (k == i || k == j)
                    k++;
                    while (l == i || l == j)
                    l--;
                    if (k >= l)
                    break;
                    b = nums[k] + nums[l];
                    if (b + a == target) {
                        // cout<<b<< " "<<a<< endl;
                        temp.clear();
                        // cout<<i<<" ";
                        // cout<<j<<" ";
                        // cout<<k<<" ";
                        // cout<<l<<" ";
                        // cout<< endl;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                        k++;
                    }
                    else if (a + b < target) {
                        k++;
                    }
                    else {
                        l--;
                    }
                }
                // i++;
            }
        }
        vector<vector<int>> ans;
        for (auto i:st) {
            ans.push_back(i);
        }
        return ans;
    }
};