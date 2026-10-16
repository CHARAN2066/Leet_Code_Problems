class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        int n = nums2.size();
        for (int i = 0; i < n; i++) {
            mp[nums2[i]] = i;
        }
        stack<int> st;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < nums2
            [i]) {
                st.pop();
            }
            if (st.empty())
            ans[i] = -1;
            else
            ans[i] = st.top();
            st.push(nums2[i]);
        }
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            res.push_back(ans[mp[nums1[i]]]);
        }
        return res;
    }
};