class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = 0,n = prices.size();
        vector<int> a(n);
        for (int i = n - 1; i >= 0; i--) {
            m = max(prices[i], m);
            a[i] = m; 
        } 
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans =  max(ans, (a[i] - prices[i]));
        }
        return ans;
    }
};