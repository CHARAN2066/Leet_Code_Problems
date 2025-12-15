class Solution {
public:
    long long int fac(int a){
        int ans=1;
        for(int i=1;i<=a;i++){
            ans*=i;
        }
        return ans;
    }
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0,c=1;
        long long n=prices.size();
        for(int i=0;i<n-1;i++){
            if((prices[i]-prices[i+1])==1){
                c++;
            }
            else{
                // cout<<c<<endl;
                ans+=((c)*(c+1))/2;
                c=1;
            }
        }
        ans+=(c*(c+1))/2;
        return ans;
    }
};