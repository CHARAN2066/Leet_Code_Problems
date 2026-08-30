class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int m = INT_MIN, mi = INT_MAX;
        for (auto i:nums) {
            m = max(m, i);
            mi = min(mi, i);
        }
        int n = nums.size(), id1, id2;
        if (n == 1)
        return 1;
        // cout<< m<< mi<< endl;
        for (int i = 0; i < n; i++) {
            if (nums[i] == m)
            id1 = i;
            if (nums[i] == mi)
            id2 = i;
        }
        // cout<< id1<< " "<< id2<< endl;
        int a = max(id1, id2) + 1;
        int b = n - min(id1, id2);
        int c = min(id1, id2) + 1 + n - max(id1, id2);
        // cout<< a<< " "<<b<<" "<< c<< endl;
        return min({a, b, c});
    }
};