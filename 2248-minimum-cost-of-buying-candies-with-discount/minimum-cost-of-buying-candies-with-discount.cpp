class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int ans=0,c=0,n=cost.size();
        for(int i=0;i<n;i++){
            if(c==2){
                // ans-=cost[i-2];
                c=0;
            }
            else
            {
                ans+=cost[i];
                c++;
            }
        }
        if(c==3){
            ans-=cost[n-1-2];
            c=0;
        }
        return ans;
        
    }
};