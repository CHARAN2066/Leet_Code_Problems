class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int t,r,n=nums.size(),ans=0;
        vector<pair<int,int>> b(32,{0,0});
        vector<int> temp;
        for(int i=0;i<n;i++){
            t=nums[i];
            temp.clear();
            while(t>0){
                r=t%2;
                temp.push_back(r);
                t=t/2;
            }         
            while(temp.size()<32){
                temp.push_back(0);
            }   
            reverse(temp.begin(),temp.end());
            for(int i=0;i<32;i++){
                if(temp[i]==0)
                b[i].first++;
                else
                b[i].second++;
            }
        }
        for(int i=0;i<32;i++){
            ans+=(b[i].first*b[i].second);
        }
        return ans;
    }
};