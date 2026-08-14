class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size(), ans = 0, l = 0;
        map<int, int> mp;
        for (int end = 0; end < n; end++) {
            mp[s[end]]++;
            while (mp[s[end]] > 2) {
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, (end - l + 1));
        }
        return ans;
    }
};