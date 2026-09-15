class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int a, b, ans = INT_MAX, n = nums.size(), s, res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            a = 0, b = n - 1;
            while (a < b) {
                if (a == i) {
                    a++;
                }
                if (b == i){
                    b--;
                }
                if (a == b)
                break;
                s = nums[a] + nums[b] + nums[i];
                if (ans > (abs(s - target))) {
                    ans = abs(s - target);
                    cout<<nums[i]<<" "<<nums[a]<<" "<<nums[b]<<endl;
                    res = s;
                }
                if (s == target)
                break;
                else if (s < target) {
                    a++;
                }
                else{
                    b--;
                }
            }
            // cout<<endl;
        }
        return res;
    }
};