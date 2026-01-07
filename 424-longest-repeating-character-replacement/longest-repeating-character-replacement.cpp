class Solution {
public:
    int characterReplacement(string s, int k) {
        int low=0,ans=0,m=0,n=s.size();
        map<char,int> mp;
        for(int end=0;end<n;end++){
            mp[s[end]]++;
            m=0;
            for(char a='A';a<='Z';a++){
                m=max(m,mp[a]);
            }
            while((end-low+1-m)>k){
                // cout<<low<<endl;
                mp[s[low]]--;
                low++;
                m=0;
                for(char a='A';a<='Z';a++){
                m=max(m,mp[a]);
                }
            }
            ans=max(ans,(end-low+1));
        }
        return ans;
        
    }
};