class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> mp;
        for (auto i:knowledge) {
            mp[i[0]] = i[1];
        }
        string ans;
        int n = s.size(), i = 0;
        string temp = "";
        while (i < n) {
            temp = "";
            if (s[i] == '(') {
                while (true) {
                    i++;
                    if (i >= n)
                    break;
                    if (s[i] == ')')
                    {
                        i++;
                        break;
                    }
                    temp.push_back(s[i]);
                }
                if (mp[temp] == "")
                ans += "?";
                else
                ans+= mp[temp];
            }
            else {
                ans.push_back(s[i]);
                i++;
            }
        }
        return ans;
    }
};