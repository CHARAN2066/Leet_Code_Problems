class Solution {
public:
    bool hasAlternatingBits(int n) {
        int a=((n^(n>>1)));
        int b=(int)log2(n)+1;
        if(a==pow(2,b)-1)
        return true;
        return false;
        // cout<<a<<" "<<pow(2,b)<<endl;
        // return a;
    }
};