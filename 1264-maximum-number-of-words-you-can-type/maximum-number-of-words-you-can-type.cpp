class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        map<char,int> mp;
        int ans=0;
        for(auto i:brokenLetters)
        mp[i]=1;
        bool flag=true;
        for(auto i:text)
        {
            if(i==' ')
            {
                if(flag)
                ans++;
                flag=true;
            }
            else
            {
                if(mp[i]==1)
                flag=false;
            }
        }
        if(flag)
        ans++;
        return ans;
        
    }
};