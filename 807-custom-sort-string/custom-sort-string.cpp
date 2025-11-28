class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;
        string ans;
        for(auto i:s)
        mp[i]++;
        for(auto i:order){
            if(mp[i]>0)
            {
                for(int j=0;j<mp[i];j++)
                ans.push_back(i);
            }
            mp[i]=0;
        }
        for(auto i:s){
            if(mp[i]>0)
            {
                for(int j=0;j<mp[i];j++)
                ans.push_back(i);
            }
            mp[i]=0;
        }
        return ans;
        
    }
};