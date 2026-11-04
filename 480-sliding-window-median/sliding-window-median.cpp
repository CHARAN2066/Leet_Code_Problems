class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s1, s2;
        vector<double> ans;
        if (k == 1) {
            for (auto i:nums) {
                ans.push_back(static_cast<double>(i));
            }
            return ans;
        }

        int n = nums.size(), m = (k / 2); 
        for (int i = 0; i < k; i++) {
            s1.insert(nums[i]);
        }
        while (s1.size() > m) {
            auto it = prev(s1.end());
            s2.insert(*it);
            s1.erase(it);
        }
        
        // for (auto i:s1) {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for (auto i:s2) {
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        int c, d;
        c = *(prev(s1.end()));
        d = *(s2.begin());
        if (k % 2 == 0) {
            ans.push_back((static_cast<double>(c) + static_cast<double>(d)) / 2);
        }
        else {
            ans.push_back(static_cast<double>(d));
        }

        for (int i = k; i < n; i++) {
            auto it = s1.find(nums[i - k]);
            if (it != s1.end()) {
                s1.erase(it);
            }
            else {
                it = s2.find(nums[i - k]);
                s2.erase(it);
            }

            if (*(s2.begin()) < nums[i]) {
                s2.insert(nums[i]);
            }
            else {
                s1.insert(nums[i]);
            }

            while (s1.size() > m) {
                auto it = prev(s1.end());
                s2.insert(*it);
                s1.erase(it);
            }
            
            while (s1.size() < m) {
                auto it = s2.begin();
                s1.insert(*it);
                s2.erase(it);
            }

            c = *(prev(s1.end()));
            d = *(s2.begin());
            
            if (k % 2 == 0) {
                ans.push_back((static_cast<double>(c) + static_cast<double>(d)) / 2);
            }
            else {
                ans.push_back(static_cast<double>(d));
            }

            // for (auto a:s1) {
            //     cout<<a<<" ";
            // }
            // cout<<endl;
            // for (auto a:s2) {
            //     cout<<a<<" ";
            // }
            // cout<<endl;
            // break;
        }
        return ans;
    }
};