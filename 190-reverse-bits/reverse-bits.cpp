class Solution {
public:
    int reverseBits(int n) {
        int a=0,r;
        vector<int> b;
        while(n>0){
            r=n%2;
            b.push_back(r);
            n=n/2;
        }
        while(b.size()<33){
            b.push_back(0);
        }
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            ans+=(b[31-i]*(1<<i));
        }
        return ans;
    }
};