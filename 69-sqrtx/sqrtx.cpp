class Solution {
public:
    int mySqrt(int x) {
        long long int low=1;
        long long int high=x;
        long long int ans=x;
        long long int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            // cout<<mid;
            if((mid*mid)<=x){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
        
    }
};