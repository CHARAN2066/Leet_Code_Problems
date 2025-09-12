class Solution {
public:
    bool doesAliceWin(string s) {
        int c=0;
        for(auto i:s)
        {
            if(i=='a'||i=='e'||i=='o'||i=='u'||i=='i')
            c++;
        }
        if(c==0)
        return false;
        else
        return true;
    }
};