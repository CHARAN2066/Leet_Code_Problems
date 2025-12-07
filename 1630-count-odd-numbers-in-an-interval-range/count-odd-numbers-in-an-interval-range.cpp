class Solution {
public:
    int countOdds(int low, int high) {
        int c=0;
        if(low%2!=0)
        c++;
        c=c+(high-low)/2;
        if(low%2==0&&high%2!=0)
        c++;
        return c;
    }
};