class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> left(n), right(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                right[i] = n;
            }
            else {
                right[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty()) 
        st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                left[i] = -1;
            }
            else {
                left[i] = st.top();
            }
            st.push(i);
        }
        int ans = 0, a, b, temp;
        for (auto i:nums) 
        ans = max(ans, i);
        for (int i = 0; i < n; i++) {
            a = left[i];
            b = right[i];
            // if (a == -1 || b == n)
            // continue;
            a++;
            b--;
            temp = (b - a + 1) * nums[i];
            // cout<<a<<" "<<b<<endl;
            ans = max(ans, temp);
        }
        return ans;
    }
};