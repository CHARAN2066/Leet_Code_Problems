class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long s=0,m=INT_MAX,c=0,z=0;
        for(auto i:matrix){
            for(auto j:i){
                if(j<0){
                    c++;
                }
                if(j==0)
                z++;
                s+=abs(j);
                m=min(m,static_cast<long long>(abs(j)));
            }
        }
        // cout<<m<<endl;
        if(z>0||c==0)
        return s;
        if(c%2!=0){
            s-=2*m;
        }
        return s;
    }
};