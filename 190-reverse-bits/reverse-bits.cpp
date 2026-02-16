class Solution {
public:
    int reverseBits(int n) {
        int ans=0,r;
        int a=31;
        while(n>0){
            r=n%2;
            ans+=(r*(1<<a));
            a--;
            n=n/2;
        }
        
        return ans;
    }
};