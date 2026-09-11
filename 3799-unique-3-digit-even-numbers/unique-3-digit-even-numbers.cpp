class Solution {
public:
    set<int> st;
    void helper(vector<int> &digits, int temp, map<int, int> &mp) {
        if (temp >= 100) {
            st.insert(temp);
            return;
        }
        for (int i = 0; i < digits.size(); i++) {
            if (mp[i] != 1) {
                temp = temp * 10 + digits[i];
                mp[i] = 1;
                helper(digits, temp, mp);
                mp[i] = 0;
                temp = temp / 10;
            }
        }
        return;
    }
    int totalNumbers(vector<int>& digits) {
        map<int, int> mp;
        int ans = 0;
        // for(auto i:digits) {
        //     cout<<i<< endl;
        // }
        helper(digits, 0, mp);   
        for (auto i:st) {
            if (i % 2 == 0)
            ans ++;
        }
        return ans;
    }
};