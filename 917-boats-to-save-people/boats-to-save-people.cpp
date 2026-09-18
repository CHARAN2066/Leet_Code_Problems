class Solution {
public:
    int numRescueBoats(vector<int>& people, int target) {
        sort(people.begin(), people.end());
        int n = people.size(), i = 0, ans = 0, j = n - 1;
        while (i < j) {
            if (people[i] + people[j] <= target) {
                ans++;
                people[i] = -1;
                people[j] = -1;
                i++;
                j--;
            }
            else {
                j--;
            }
        }
        for (auto i:people) {
            if (i != -1)
            ans++;
        }
        return ans;
    }
};