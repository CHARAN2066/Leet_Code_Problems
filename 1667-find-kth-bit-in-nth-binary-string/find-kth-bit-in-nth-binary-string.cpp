class Solution {
public:
    string invert(string s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            s[i]='0';
            else
            s[i]='1';
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string s;
        s.push_back('0');
        while(s.size()<=k)
        {
            string temp=invert(s);
            reverse(temp.begin(),temp.end());
            s.push_back('1');
            s=s+temp;
        }
        // cout<<s;
        return s[k-1];
    }
};