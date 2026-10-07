class Solution {
public:
    vector<string> ans;
    int ma = 0;
    void helper(string s, int i, int n, string temp, int l, int r) {
        if (l < r) {
            return;
        }
        if (i == n) {
            // cout<<"s";
            if (l == r) {
                if (ma <= temp.size())
                {
                    ans.push_back(temp);
                    ma = temp.size();
                }
            }
            return;
        }
        if (s[i] != ')' && s[i] != '(') {
            temp.push_back(s[i]);
            helper(s, i + 1, n, temp, l, r);
            return;
        }
        else if (s[i] == '(') {
            temp.push_back(s[i]);
            helper(s, i + 1, n, temp, l + 1, r);
        }
        else if (s[i] == ')') {
            temp.push_back(s[i]);
            helper(s, i + 1, n, temp, l, r + 1);
        }
        temp.pop_back();
        helper(s, i + 1, n, temp, l, r);
        return;
    }
    bool check(string curr) {
        int balance = 0;
        for (auto i:curr) {
            if (i == '(')
            balance++;
            else if (i ==')')
            balance--;
            if (balance < 0)
            return false;
        }
        return balance == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size(), si;
        queue<string> q;
        q.push(s);
        string curr, new_string;
        map<string, bool> visted;
        while (!q.empty()) {
            si = q.size();
            for (int i = 0; i < si; i++) {
                curr = q.front();
                q.pop();
                if (visted[curr])
                continue;
                visted[curr] = true;
                // cout<<curr<<" ";
                if (check(curr)) {
                    ans.push_back(curr);
                    continue;
                }
                if (ans.size() > 0 || curr.size() == 1)
                continue;
                for (int j = 0; j < curr.size(); j++) {
                    if (curr[j] != '(' && curr[j] != ')')
                    continue;
                    new_string = curr.substr(0, j) + curr.substr(j + 1, (curr.size() - j - 1));
                    q.push(new_string);
                }
            }
            // cout<<endl;
            if (ans.size() > 0)
            break;
        }
        if (ans.size() == 0)
        ans.push_back("");
        return ans;
    }
};