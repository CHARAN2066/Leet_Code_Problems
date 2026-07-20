class Solution {
public:
    string convert(string s, int k) {
        vector<string> ans (k);
        int n = s.size(), l = 0;
        while (l < n) {
            for (int i = 0; i < k; i++) {
                if (l >= n)
                break;
                ans[i].push_back(s[l]);
                l++;
            }
            for (int i = k - 2; i >= 1; i--) {
                if (l >= n)
                break;
                ans[i].push_back(s[l]);
                l++;
            }
        }
        string res = "";
        for (auto i:ans) {
            res += i;
        }
        return res;
        
    }
};