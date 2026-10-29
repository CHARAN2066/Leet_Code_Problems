class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
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
        int a, b, size, c;
        for (int i = 0; i < n; i++) {
            a = left[i];
            b = right[i];
            a++;
            b--;
            // cout<<a<<" "<<b<<" "<<nums[i]<<endl;
            size = (b - a + 1);
            double c = ((static_cast<double>(threshold) / static_cast<double>(size)));
            if (static_cast<double>(nums[i]) > c)
            {
                // cout<<i<<endl;
                return (b - a + 1);
            }
        }        
        return -1;
    }
};