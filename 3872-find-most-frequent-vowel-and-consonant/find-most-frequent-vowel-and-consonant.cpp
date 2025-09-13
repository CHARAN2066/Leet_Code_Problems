class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int> mp;
        for(auto i:s)
        mp[i]++;
        int m1=max({mp['a'],mp['e'],mp['i'],mp['o'],mp['u']});
        int m2=0;
        for(char i='a';i<='z';i++)
        {
            if(i=='a'||i=='e'||i=='i'||i=='o'||i=='u')
            continue;
            m2=max(m2,mp[i]);
        }
        return m1+m2;
    }
};