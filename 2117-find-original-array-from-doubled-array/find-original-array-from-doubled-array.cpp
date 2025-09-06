class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int> mp;
        int n=changed.size();
        if(n%2!=0)
        return {};
        sort(changed.begin(),changed.end());
        vector<int> ans;
        for(auto i:changed)
        {
            if(i%2!=0)
            {   
                mp[i]++;
                continue;
            }
            // cout<<(i/2)<<" "<<mp[i/2]<<endl;
            if(mp[i/2]!=0)
            {
                ans.push_back(i/2);
                mp[i/2]--;
                mp[i]--;
            }
            mp[i]++;
        }
        if(ans.size()!=(n/2))
        return {};
        return ans;
        
    }
};