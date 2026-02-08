class Solution {
public:
    int minBitFlips(int start, int goal) {
        int a=start^goal,r,c=0;
        while(a>0){
            r=a%2;
            if(r==1)
            c++;
            a=a/2;
        }
        return c;
        
    }
};