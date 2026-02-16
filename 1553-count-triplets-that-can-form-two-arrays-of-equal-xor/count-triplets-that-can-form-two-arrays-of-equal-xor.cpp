class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size(),a=0,ans=0;
        for(int i=0;i<n;i++){
            a=0;
            for(int j=i;j<n;j++){
                a^=arr[j];
                // if((j-i+1)<=2)
                // continue;
                if(a==0)
                {
                    ans+=(j-i);
                }
            }
        }
        return ans;
        
    }
};