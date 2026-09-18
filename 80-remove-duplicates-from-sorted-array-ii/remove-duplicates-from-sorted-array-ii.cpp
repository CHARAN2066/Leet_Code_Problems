class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c = 0, slow = 2, fast = 2, n = nums.size();
        while (fast < n) {
            if (nums[slow - 2] == nums[fast]){
                fast++;
                c++;
            }
            else {
                nums[slow++] = nums[fast++];
            }
        }
        return n - c;
        
    }
};