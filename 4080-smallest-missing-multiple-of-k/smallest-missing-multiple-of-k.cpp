class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto i:nums) {
            mp[i]++;
        }
        int i = 2, a = k;
        while (true) {
            if (mp[k] == 0)
            return k;
            // cout<< k<< endl;
            k += a;
            i++;
        }
        return -1;
    }
};