class Solution {
public:
    bool canMakeSubsequence(string s, string t) 
    {
        int m=s.size(),n=t.size(),i=0,j=0;
        if(m>n)
            return false;
        vector<int> pre(m,-1);
        while(i<n&&j<m){
            if(s[j]==t[i]){
                pre[j]=i;
                j++;
            }
            i++;
        }
        i=n-1;
        j=m-1;
        vector<int> suf(m,-1);
        while(i>=0&&j>=0){
            if(s[j]==t[i]){
                suf[j]=i;
                j--;
            }
            i--;
        }
        if(m==1||pre[m-1]!=-1)
            return true;
        if((pre[m-2]!=-1&&pre[m-2]<n-1)||(suf[1]!=-1&&suf[1]>0))
            return true;
        for(int i=1;i<m-1;i++){
               if(pre[i-1]!=-1&&suf[i+1]!=-1&&(suf[i+1]-pre[i-1])>=2)
                   return true;
        }
        return false;
    }
};