class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int s,l=0,r=n-1;
        while(l<=r){
            s=numbers[l]+numbers[r];
            if(s==target){
                return {l+1,r+1};
            }
            if(s<target){
                l++;
            }
            else{
                r--;
            }
        }
        return {-1,-1};
    }
};