class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> prefix(n);
        prefix[0]=arr[0];
        int a=0;
        for(int i=0;i<n;i++)
        {
            a=a^arr[i];
            prefix[i]=a;
        }
        vector<int> ans;
        for(auto i:queries){
            if(i[0]==0)
            ans.push_back(prefix[i[1]]);
            else
            ans.push_back(prefix[i[0]-1]^prefix[i[1]]);
        }
        return ans;
    }
};