class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> s;
        for (auto i:nums) s.insert(i);
        // for (auto i:s) cout<< i<< " ";
        // cout<<endl;
        for (int i = 0; i < k - 1; i++) {
            // cout<< *(prev(s.end()))<< endl;
            s.erase(prev(s.end()));
        }
        return *(prev(s.end()));
    }
};