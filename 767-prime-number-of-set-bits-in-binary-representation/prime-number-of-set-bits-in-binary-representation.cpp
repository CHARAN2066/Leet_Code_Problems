class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int t,o=0,ans=0;
        vector<int> prime(20,1);
        prime[2]=0;
        prime[3]=0;
        prime[5]=0;
        prime[7]=0;
        prime[11]=0;
        prime[13]=0;
        prime[17]=0;
        prime[19]=0;
        for(int i=left;i<=right;i++){
            t=i;
            o=0;
            while(t>0){
                o++;
                t=t&(t-1);
            }
            if(prime[o]==0)
            ans++;
        }
        return ans;
        
    }
};