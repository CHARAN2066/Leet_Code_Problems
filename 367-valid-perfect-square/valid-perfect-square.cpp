class Solution {
public:
    bool isPerfectSquare(int n) {
        long long int low=1,high=n,mid;
        while(low<=high){
            mid=high-(high-low)/2;
            if(mid*mid==n)
            return true;
            else if(mid*mid<n){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
        
    }
};