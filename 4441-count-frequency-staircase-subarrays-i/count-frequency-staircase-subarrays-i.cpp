class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size(), t = 1, l = 0, c = 0, s, ans  = 0;
        bool flag = false;
        map<int, int> mp, mp2;
        // while (l <= 1500) {
        //     l = (t * (t + 1)) / 2;
        //     c++;
        //     // cout<<l<<endl;
        //     t++;
        // }
        // cout<<c<<endl;
        for (int i = 0; i < n; i++) {
            mp.clear();
            t = 1;
            for (int j = i; j < n; j++) {
                mp[nums[j]]++;
                l = (t * (t + 1)) / 2;
                if ((j - i + 1) == l) {
                    // cout<<i<<" "<<j<<endl;
                    mp2.clear();
                    s = 1;
                    flag = false;
                    for (int k = i; k <= j; k++) {
                        if (mp2[nums[k]] == 0) {
                            if (mp[nums[k]] != s) {
                                // if (i == 0 && j == 5)
                                // cout<<s<<" "<<nums[k]<<endl;
                                flag = true;
                                break;
                            }
                            s++;
                        }
                        mp2[nums[k]]++;
                    }
                    if (!flag) {
                        // cout<<i<<" "<<j<<endl;
                        ans++;
                    }
                    t++;
                }
            }
        }
        return ans;
    }
};