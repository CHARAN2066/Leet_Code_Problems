class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size(), i = 0, j = n - 1;
        bool flag = true, ans = true, res = true;
        while (i < j) {
            if (s[i] != s[j]) {
                if (flag) {
                    flag = false;
                    i++;
                }
                else  {
                    ans = false;
                    break;
                }
            }
            else  {
                i++;
                j--;
            }
        }
        flag = true;
        i = 0, j = n - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                if (flag) {
                    flag = false;
                    j--;
                }
                else  {
                    res = false;
                    break;
                }
            }
            else  {
                i++;
                j--;
            }
        }
        return ans || res;
    }
};