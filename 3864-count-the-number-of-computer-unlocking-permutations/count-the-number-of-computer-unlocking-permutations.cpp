class Solution {
public:
    int countPermutations(vector<int>& a) {
        int n=a.size(),ans=1,m=INT_MAX;
        for(auto i:a){
            m=min(m,i);
        }
        int c=0;
        for(auto i:a){
            if(m==i)
            c++;
        }
        if(a[0]!=m)
        return 0;
        if(c>1)
        return 0;
        long long int pr=1;
        long long int mod=1e9+7;
        for(int i=1;i<n;i++)
        pr=(pr*i)%mod;
        return pr;
    }
};