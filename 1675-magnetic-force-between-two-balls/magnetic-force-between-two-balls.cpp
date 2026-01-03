class Solution {
public:
    bool fun(int mid,vector<int> &position,int m){
        int n=position.size();
        int a=position[0];
        m--;
        for(int i=1;i<n;i++){
            if((position[i]-a)>=mid){
                a=position[i];
                m--;
                if(m==0)
                return true;
            }
        }
        return false;
        
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size(),low=0,high=position[n-1]-position[0];
        int mid,ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(fun(mid,position,m)){
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