class Solution {
public:
    int fun(vector<int> &arr,int cap){
        int ans=0,c=0,a=0;
        for(auto i:arr){
            if((c+i)>cap)
            {
                ans++;
                c=0;
            }
            c+=i;
        }
        if(c<=cap)
        ans++;
        return ans;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int l=0,h=0,mid;
        for(auto i:arr){
            l=max(l,i);
            h+=i;
        }
        int ans=-1;
        while(l<=h){
            mid=(l+h)/2;
            if(fun(arr,mid)<=days){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};