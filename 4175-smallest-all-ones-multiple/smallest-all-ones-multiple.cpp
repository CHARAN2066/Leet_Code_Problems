class Solution {
public:
    int minAllOneMultiple(int k) {
        int c=0,a=0;
        while(k>0){
            a=(a*10+1)%k;
            c++;
            if(a==0)
            return c;
            if(c>k)
            return -1;
        }
        return -1;
    }
};