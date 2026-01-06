class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> mp;
        int u=0,l=0,ans=0,s=0,n=fruits.size();
        for(int end=0;end<n;end++){
            mp[fruits[end]]++;
            if(mp[fruits[end]]==1){
                u++;
            }
            while(u>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0)
                u--;
                l++;
            }
            // cout<<l<<" "<<end<<endl;
            ans=max(ans,end-l+1);
        }
        return ans;
    }
};