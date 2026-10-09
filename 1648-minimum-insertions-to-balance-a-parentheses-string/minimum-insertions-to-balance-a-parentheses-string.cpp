class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            }
            else if (i != n - 1 && s[i] == ')' && s[i] == s[i + 1]) {
                if (st.empty()) {
                    ans++;
                }
                else
                st.pop();
                i++;
            }
            else {
                ans++;
                if (st.empty()) 
                ans++;
                else
                st.pop();
            }
        }
        ans += (st.size() * 2);
        return ans;
    }
};