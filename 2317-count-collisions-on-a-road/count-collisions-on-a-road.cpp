class Solution {
public:
    int countCollisions(string s) {
        int n=s.size(),a,b;
        for(int i=0;i<n;i++){
            if(s[i]=='R'||s[i]=='S')
            {
                a=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='L'||s[i]=='S')
            {
                b=i;
                break;
            }
        }
        if(a>b)
        return 0;
        int c=0;
        for(int i=a;i<=b;i++){
            if(s[i]=='S')
            continue;
            else
            c++;
        }
        return c++;
    }
};