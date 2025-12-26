class Solution {
public:
    int bestClosingTime(string c) {
        int y=0,n=0;
        for(auto i:c){
            if(i=='Y')
            y++;
            else
            n++;
        }
        int res=0,t;
        int y1=0,n1=0;
        int ans=INT_MAX;
        int n_=c.size();
        for(int i=0;i<n_;i++){
            t=n1+(y-y1);
            if(ans>t){
                ans=t;
                res=i;
            }
            if(c[i]=='Y')
            y1++;
            else
            n1++;
        }
        if(ans>n){
            ans=n;
            res=n_;
        }
        if(ans>y){
            ans=y;
            res=0;
        }
        // if(res==1)
        return res;
    }
};