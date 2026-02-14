class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size(),t,s=1<<n,r;
        vector<int> binary,temp;
        vector<vector<int>> ans;
        for(int i=0;i<s;i++){
            t=i;
            binary.clear();
            temp.clear();
            while(t>0){
                r=t%2;
                binary.push_back(r);
                t=t/2;
            }
            reverse(binary.begin(),binary.end());
            // for(auto j:binary) cout<<j<<" ";
            // cout<<endl;
            while(binary.size()<n)
            binary.insert(binary.begin(),0);
            for(int j=0;j<n;j++){
                // cout<<binary[j]<<" ";
                if(binary[j]==1)
                temp.push_back(nums[j]);
            }
            // cout<<endl;
            ans.push_back(temp);
        }
        return ans;
    }
};