class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0, c = 1;
        for (auto i:s) {
            ans += (c * (26 - (i - 'a')));
            c++;
        }
        return ans;
    }
};