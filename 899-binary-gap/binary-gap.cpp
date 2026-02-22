class Solution {
public:
    int binaryGap(int n) {
        int r,b=0,ans=0,t=-1;
        while(n>0){
            r=n%2;
            b++;
            if(r==1)
            {
                if(t!=-1)
                ans=max(ans,(b-t));
                t=b;
            }
            n=n/2;
        }
        return ans;
    }
};