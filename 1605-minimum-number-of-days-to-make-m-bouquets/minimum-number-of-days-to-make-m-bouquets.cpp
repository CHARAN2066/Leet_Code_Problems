class Solution {
public:
    int fun(vector<int> &arr,int day,int k){
        int ans=0,c=0;
        for(auto i:arr){
            if(i<=day){
                c++;
                if(c==k)
                {
                    c=0;
                    ans++;
                }
            }
            else{
                c=0;
            }
        }
        if(c==k)
        ans++;
        return ans;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int l=INT_MAX,h=0,mid;
        for(auto i:arr){
            l=min(l,i);
            h=max(h,i);
        }
        // cout<<l<<" "<<h<<endl;
        int ans=-1;
        while(l<=h){
            mid=(l+h)/2;
            // cout<<mid<<" "<<fun(arr,mid,k)<<endl;
            if(fun(arr,mid,k)>=m){
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