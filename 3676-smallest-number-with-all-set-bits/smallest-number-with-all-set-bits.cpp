class Solution {
public:
    int smallestNumber(int n) {
        int c=0,r;
        while(n>0)
            {
                r=n%2;
                c++;
                n=n/2;
            }
        int ans=0;
        for(int i=c-1;i>=0;i--)
            ans+=pow(2,(c-1)-i);
        return ans;
        
    }
};