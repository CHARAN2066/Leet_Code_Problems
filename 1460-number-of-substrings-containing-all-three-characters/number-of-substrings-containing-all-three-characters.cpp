class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),ans=0,st=0;
        map<char,int> mp;
        for(int end=0;end<n;end++){
            mp[s[end]]++;
            while(mp['a']>0&&mp['b']>0&&mp['c']>0){
                ans+=(n-end);
                mp[s[st]]--;
                st++;
            }
        }
        return ans;
    }
};