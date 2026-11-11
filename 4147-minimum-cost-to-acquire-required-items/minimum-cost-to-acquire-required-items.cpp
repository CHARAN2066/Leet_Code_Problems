class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0,a;
        if(cost1+cost2>=costBoth){
            a=min(need1,need2);
            ans+=(a*static_cast<long long>(costBoth));
            need1-=a;
            need2-=a;
        }
        else{
            ans+=(static_cast<long long>(need1)*static_cast<long long>(cost1));
            ans+=(static_cast<long long>(need2)*static_cast<long long>(cost2));
            return ans;
        }
        if(cost1>=costBoth){
            ans+=(static_cast<long long>(need1)*static_cast<long long>(costBoth));
            need2=max(need2-need1,0);
        }
        else{
            ans+=static_cast<long long>(need1)*static_cast<long long>(cost1);
        }
        
        if(cost2>=costBoth){
            ans+=static_cast<long long>(need2)*static_cast<long long>(costBoth);
        }
        else{
            ans+=static_cast<long long>(need2)*static_cast<long long>(cost2);
        }
        return ans;
    }
};