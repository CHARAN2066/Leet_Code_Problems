class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ma=0,mi=LLONG_MAX;
        for(auto i:nums){
            ma=max(ma,static_cast<long long>(i));
            mi=min(mi,static_cast<long long>(i));
        }
        return (ma-mi)*k;
    }
};