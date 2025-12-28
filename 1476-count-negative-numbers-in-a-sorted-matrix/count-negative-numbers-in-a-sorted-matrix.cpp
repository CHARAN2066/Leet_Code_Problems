class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size(),l,h,mid,ans,res=0;
        for(int i=0;i<n;i++){
            l=0;
            h=m-1;
            ans=-1;
            while(l<=h){
                mid=(l+h)/2;
                if(grid[i][mid]>=0){
                    l=mid+1;
                }
                else{
                    ans=mid;
                    h=mid-1;
                }
            }
            if(ans==-1)
            continue;
            // cout<<ans<<endl;
            res+=(m-ans);
        }
        return res;
        
    }
};