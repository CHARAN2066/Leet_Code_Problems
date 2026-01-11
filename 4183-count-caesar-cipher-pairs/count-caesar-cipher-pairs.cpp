class Solution {
public:
    long long countPairs(vector<string>& words) {
        map<string,long long> mp;
        long long ans=0;
        for(auto i:words){
            mp[i]++;
        }
        for(auto i:mp){
            ans+=((i.second*(i.second-1))/2);
        }
        cout<<ans<<endl;
        long long m=words[0].size();
        string t;
        long long n=words.size();
        // if(n%2==0)
        // n=n/2;
        // else
        // n=(n/2)+1;
        for(long long i=0;i<n;i++){
            t=words[i];
            for(long long j=0;j<26;j++){
                for(long long k=0;k<m;k++){
                    if(t[k]=='z')
                    t[k]='a';
                    else
                    t[k]++; 
                }
                if(mp[t]>=1)
                {
                    if(words[i]!=t)
                    {
                        // cout<<words[i]<<" "<<t<<endl;
                        ans+=mp[t];
                    }
                }
            }
            mp[words[i]]--;
        }
        return ans;
    }
};