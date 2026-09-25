class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int r1 = 0, w1 = 0, r2 = 0, w2 = 0, n1 = s.size(), n2 = t.size();
        while (r1 < n1 && w1 < n1) {
            if (s[r1] == '#') {
                r1++;
                if (w1 != 0)
                w1--;
            }
            else {
                s[w1] = s[r1];
                r1++;
                w1++;
            }
        }   
        while (r2 < n2 && w2 < n2) {
            if (t[r2] == '#') {
                r2++;
                if (w2 != 0)
                w2--;
            }
            else {
                t[w2] = t[r2];
                r2++;
                w2++;
            }
        }   
        if (w1 != w2)
        return false;
        for (int i = 0; i < w1 && i < w2; i++) {
            if (s[i] != t[i])
            return false;
        }
        return true;
    }
};