class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (9 * num < sum)
        return "";
        string ans;
        while (num--) {
            if (sum < 9)
            {
                ans += (sum + '0');
                sum = 0;
            }
            else 
            {
                ans += '9';
                sum -= 9;
            }
        }
        return ans;
    }
};