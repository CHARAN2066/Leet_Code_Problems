class Solution {
public:
    int maxProduct(int n) {
        int temp=n;
        int m =INT_MIN;
        int m2=INT_MIN;
        vector<int>ans;
        while(n>0){
            int t=n%10;
            ans.push_back(t);
            n=n/10; 
        }
        sort(ans.begin(),ans.end(),greater<int>());
        return ans[0]*ans[1];
        
    }
};