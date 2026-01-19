class Solution {
public:
    bool isalphanumeric(char a){
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        return true;
        return false;
    }
    char iscaptial(char a){
        if(a>='A'&&a<='Z')
        return a+32;
        return a;
    }
    bool isPalindrome(string s) {
        int n=s.size();
        int l=0,r=n-1;
        // cout<<'A'-'a'<<endl;
        while(l<=r){
            if(!isalphanumeric(s[l]))
            l++;
            if(!isalphanumeric(s[r]))
            r--;
            if(isalphanumeric(s[l])&&isalphanumeric(s[r])){
                if(iscaptial(s[l])==iscaptial(s[r]))
                {
                    l++;
                    r--;
                }
                else{
                    cout<<iscaptial(s[l])<<" "<<iscaptial(s[r])<<endl;
                    return false;
                }
            }
        }
        return true;
        
    }
};