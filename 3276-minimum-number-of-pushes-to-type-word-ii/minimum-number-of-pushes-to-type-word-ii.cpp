class Solution {
public:
    int minimumPushes(string word) {
        map<char, int> mp;
        for (auto i:word) {
            mp[i]++;
        }
        vector<pair<int, char>> freq;
        for (auto i:mp) {
            freq.push_back({i.second, i.first});
        }
        sort(freq.begin(), freq.end(), greater<pair<int,int>>());
        int s = freq.size(), c = 0, ans = 0;
        for (int i = 0; i < s; i++) {
            // cout<< freq[i].second<< " "<< freq[i].first<<endl;
            c++;
            if (c <= 8)
            ans += mp[freq[i].second];
            else if(c <= 16)
            ans += 2 * mp[freq[i].second];
            else if(c <= 24)
            ans += 3 * mp[freq[i].second];
            else 
            ans += 4 * mp[freq[i].second];
        }
        return ans;



        
    }
};