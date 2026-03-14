class Solution {
public:
    string ans;
    int times;
    void helper(int n,string t,char pre){
        if(n==0){
            if(times>0){
                ans=t;
                times--;
            }
            return;
        }
        for(char c='a';c<='c';c++){
            if(pre!=c)
            {
                t.push_back(c);
                helper(n-1,t,c);
                t.pop_back();
            }
        }
        return;
    }
    string getHappyString(int n, int k) {
        times=k;
        string t="";
        helper(n,t,'d');
        if(times!=0)
        return "";
        return ans;
    }
};