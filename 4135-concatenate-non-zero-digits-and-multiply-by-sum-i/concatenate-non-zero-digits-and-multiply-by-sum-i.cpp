class Solution {
public:
    long long sumAndMultiply(int a) {
        long long r, rev = 0, num = 0, sum = 0, n = a;
        while (n > 0) {
            r = n % 10;
            rev = rev * 10 + r;
            n = n / 10;
        }
        n = rev;
        while (n > 0) {
            r = n % 10;
            if (r != 0) {
                num = num * 10 + r;
                sum += r;
            }
            n = n / 10;
        }
        return num * sum;
    }
};