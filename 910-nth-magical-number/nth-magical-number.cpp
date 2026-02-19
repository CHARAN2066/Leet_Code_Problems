class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long int low=min(a,b),high=n*low,mid,ca,cb,cc,c=0,ans=-1;
        // cout<<low<<" "<<high<<endl;
        while(low<=high){
            mid=low+(high-low)/2;
            ca=mid/a;
            cb=mid/b;
            cc=mid/(a*b/__gcd(a,b));
            c=ca+cb-cc;
            // cout<<mid<<" "<<c<<endl;
            if(c<n){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        long long mod=1e9+7;
        return ans%mod;
    }
};