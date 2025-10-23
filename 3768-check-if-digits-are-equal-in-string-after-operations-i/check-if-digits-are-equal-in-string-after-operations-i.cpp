class Solution {
public:
    bool hasSameDigits(string s) {
        string ans,temp;
        int n=s.size();
        for(auto i:s)
        ans.push_back(i);
        while(ans.size()>2){
            n=ans.size();
            temp=ans;
            ans="";
            for(int i=0;i<n-1;i++)
            {
                ans.push_back((temp[i]-'0'+temp[i+1]-'0')%10);
            }
        }
        if(ans[0]!=ans[1])
        return false;
        else 
        return true;

        
    }
};