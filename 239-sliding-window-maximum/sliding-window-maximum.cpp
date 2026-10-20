class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < k; i++)
        mp[nums[i]]++;
        ans.push_back(prev(mp.end())->first);
        for (int i = k; i < n; i++) {
            mp[nums[i - k]]--;
            if(mp[nums[i - k]] == 0) {
                mp.erase(nums[i - k]);
            }
            mp[nums[i]]++;
            // for (auto j:mp) {
            //     cout<<j.first<<" "<<j.second<<endl;
            // }
            ans.push_back(prev(mp.end())->first);

        }
        return ans;
    }
};