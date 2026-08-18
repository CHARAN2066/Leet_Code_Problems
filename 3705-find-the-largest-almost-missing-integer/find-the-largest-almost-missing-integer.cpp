class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<bool> a(51, false);
        int n = nums.size();
        map<int, int> mp;
        for (int j = 0; j <= n - k; j++) {
            for (int i = j; i < j + k;  i++) {
                cout<< nums[i]<< " ";
                a[nums[i]] = true;
            }
            cout<< endl;
            for (int i = 0; i < 51; i++) {
                if (a[i]) {
                    mp[i]++;
                }
                a[i] = false;
            }
        }
        int ans = -1;
        for (auto i:mp) {
            if (i.second == 1)
            ans = max(ans, i.first);
        }
        return ans;
    }
};