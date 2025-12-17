class Solution {
public:
    int arrangeCoins(int n) {
        long long int low=1,high=n,mid,s;
        int ans;
        while(low<=high){
            mid=high+(low-high)/2;
            s=(mid*(mid+1))/2;
            if(s>n){
                
                high=mid-1;
            }
            else{
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
};