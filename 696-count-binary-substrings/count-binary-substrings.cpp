class Solution {
public:
    int countBinarySubstrings(string s) {
        int z=1,prev=0,ans=0;
        int n=s.size();
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                z++;
            }
            else{
                // cout<<z<<" "<<prev<<endl;
                if(prev!=-1)
                ans+=min(z,prev);
                prev=z;
                z=1;
            }
        }
        ans+=min(z,prev);
        return ans;
        
    }
};