class Solution {
public:
    int concatenatedBinary(int n) {
        long long int b=1,a=1,mod=1e9+7;
        for(int i=2;i<=n;i++){
            if((i&(i-1))==0)
            b++;
            a=(a<<b);
            a=(a+i)%mod;
        }
        return a;
    }
};