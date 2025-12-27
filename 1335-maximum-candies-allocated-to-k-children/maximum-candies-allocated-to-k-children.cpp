class Solution {
public:
    long long fun(vector<int> &candies,long long m){
        long long ans=0;
        for(auto i:candies){
            ans+=(static_cast<long long>(i)/m);
        }
        return ans;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        sort(candies.begin(),candies.end(),greater<int>());
        long long l=1,h=0,mid;
        for(auto i:candies){
            h=max(h,static_cast<long long>(i));
        }
        // cout<<fun(candies,5);
        int ans=0;
        while(l<=h){
            mid=(l+h)/2;
            if(fun(candies,mid)>=k){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};