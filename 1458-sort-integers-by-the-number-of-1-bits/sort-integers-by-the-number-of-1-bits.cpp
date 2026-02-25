class Solution {
public:
    int fun(int n){
        int a=0;
        while(n>0){
            a++;
            n=n&(n-1);
        }
        return a;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> a;
        int n=arr.size();
        for(int i=0;i<n;i++)
        a.push_back({fun(arr[i]),arr[i]});
        sort(a.begin(),a.end());
        vector<int> ans;
        for(auto i:a)
        ans.push_back(i.second);
        return ans;

    }
};