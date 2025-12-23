class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        double ans=0,n=arr.size();
        for(double i=0;i<n;i++){
            // cout<<ceil(((n-i)*(i+1)*arr[i])/2)<<endl;
            ans+=((ceil((((n-i)*(i+1))/2)))*arr[i]);
        }
        return ans;
        
    }
};