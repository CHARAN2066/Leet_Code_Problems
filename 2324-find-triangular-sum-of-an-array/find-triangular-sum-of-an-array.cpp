class Solution {
public:
    int triangularSum(vector<int>& temp) {
        int n=temp.size();
        while(temp.size()>=1)
        {
            n=temp.size();
            for(int i=0;i<n-1;i++)
            {
                temp[i]=(temp[i]+temp[i+1])%10;
            }
            temp.pop_back();
            // for(auto i:temp)
            // cout<<i<<" ";
            // cout<<endl;
        }
        return temp[0];
        
    }
};