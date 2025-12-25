class Solution {
public:
    long long int fun(vector<int> &piles,long long int a){
        long long int ans=0;
        for(auto i:piles){
            if(i%a!=0)
            ans+=(i/a)+1;
            else
            ans+=(i/a);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int m=0;
        for(auto i:piles){
            m=max(m,static_cast<long long>(i));
        }
        long long int low=1,high=m,mid,ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(fun(piles,mid)>h){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};