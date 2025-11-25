class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long int a=1;
        long long int ans=1;
        if((k%2==0)||(k%10==5))
        return -1;
        while(true)
        {
            // if(ans>=25)
            // return -1;
            if(a%k==0)
            return ans;
            else
            a=a*10+1;
            a=a%k;
            ans++;
        }
        return -1;
        
    }
};