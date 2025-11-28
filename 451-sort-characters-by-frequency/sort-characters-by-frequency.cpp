class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(auto i:s)
        mp[i]++;
        vector<pair<int,char>> arr;
        for(auto i:s)
        {
            if(mp[i]==0)
            continue;
            arr.push_back({mp[i],i});
            mp[i]=0;
        }
        sort(arr.begin(),arr.end(),greater<pair<int,char>>());
        string ans;
        for(auto i:arr)
        {
            for(int j=0;j<i.first;j++)
            ans.push_back(i.second);
        }
        return ans;
    }
};