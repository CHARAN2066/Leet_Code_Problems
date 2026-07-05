class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        map<int, int> frequency;
        for(int i = 0; i < n; i++){
            frequency[nums[i]]++;
        }
        if (frequency[nums[(n/2)]] == 1) {
            return true;
        }
        return false;
    }
};