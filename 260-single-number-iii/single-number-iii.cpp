class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int x=0;
        for(auto i:nums) x^=i;
        int r=(x&(x-1))^x;
        int b1=0,b2=0;
        for(auto i:nums){
            if(i&r)
            b1^=i;
            else
            b2^=i;
        }
        return {b1,b2};
        
    }
};