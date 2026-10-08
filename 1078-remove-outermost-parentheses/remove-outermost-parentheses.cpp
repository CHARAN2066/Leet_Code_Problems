class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int n = s.size();
        st.push(s[0]);
        string ans;
        for (int i = 1; i < n; i++) {
            if (!st.empty()) {
                ans.push_back(s[i]);
            }
            if (s[i] == ')')
            st.pop();
            else
            st.push(s[i]);
            if (st.empty())
            ans.pop_back();
        }
        return ans;
    }
};