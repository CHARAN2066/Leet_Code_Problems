class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int mod = 1e9 + 7;
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
        vector<long long int> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        long long int a, b, sum, temp, ans = 0;
        for (int i = 0; i < n; i++) {
            a = left[i];
            b = right[i];
            a++;
            b--;
            if (a == 0)
            sum = prefix[b];
            else
            sum =  prefix[b] - prefix[a - 1];
            temp = (sum * nums[i]);
            // cout<<a<<" "<<b<<" "<<sum<<" "<<temp<<endl;
            // cout<<sum<<endl;
            // cout<<temp<<endl;
            ans = max(ans, temp);
        }
        return ans % mod;
    }
};