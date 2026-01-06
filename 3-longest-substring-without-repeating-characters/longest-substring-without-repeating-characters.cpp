class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,ans=0;
        int n=s.size();
        map<char,int> mp;
        for(int end=0;end<n;end++){
            mp[s[end]]++;            
            while(mp[s[end]]>1){
                mp[s[l]]--;
                l++;
                // cout<<l<<" "<<end<<endl;
                ans=max(ans,end-l+1);
            }
            ans=max(ans,end-l+1);
        }
        return ans;
        
    }
};