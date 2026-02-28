class Solution {
public:
    int concatenatedBinary(int n) {
        long long int b,a=1,mod=1e9+7;
        for(int i=2;i<=n;i++){
            b=(log2(i)+1);
            a=(a<<b);
            a=(a+i)%mod;
            // cout<<a<<endl;
        }
        return a;
    }
};