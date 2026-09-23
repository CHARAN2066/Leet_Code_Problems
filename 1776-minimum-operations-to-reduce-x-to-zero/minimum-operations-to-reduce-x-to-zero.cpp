class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        map<int, int> mp;
        int n = nums.size(), suf= 0, c = 0, ans = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            suf += nums[i];
            c++;
            if (suf == x)
            ans = min(ans, c);
            mp[suf] = c;
        }
        int pre = 0, t;
        for (int i = 0; i < n; i++) {
            pre += nums[i];
            // cout<<pre<<" ";
            if (pre == x)
            ans = min(ans, (i + 1));
            if (pre > x)
            break;
            if (mp[x - pre] == 0)
            continue;
            // cout<<mp[x - pre]<<" ";
            t = mp[x - pre] + (i + 1);
            // cout<<t<<endl;
            if (t <= n) {
                // cout<<t<<endl;
                ans = min(ans, t);
            }
        }
        // cout<<ans<<endl;
        if (ans == INT_MAX)
        return -1;
        return ans;
    }
};