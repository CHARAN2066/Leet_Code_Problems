class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        map<int,int> m1;
        // for(auto i:nums4)
        // mp[i]++;
        int ans=0;
        for(auto i:nums1){
            for(auto j:nums2){
                m1[i+j]++;
            }
        }
        map<int,int> m2;
        for(auto i:nums3){
            for(auto j:nums4){
                m2[i+j]++;
            }
        }
        for(auto i:nums1){
            for(auto j:nums2){
                if(m2[-(i+j)]>0)
                ans+=m2[-(i+j)];
            }
        }
        return ans;
    }
};