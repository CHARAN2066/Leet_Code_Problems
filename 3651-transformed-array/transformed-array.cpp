class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size(),a,id;
        vector<int> res(n);
        for(int i=0;i<n;i++){
            if(nums[i]==0)
            res[i]=nums[i];
            if(nums[i]>0){
                a=nums[i];
                id=i;
                while(a--){
                    id=(id+1)%n;
                }
                // cout<<id<<endl;
                res[i]=nums[id];
            }
            if(nums[i]<0){
                a=abs(nums[i]);
                id=i;
                while(a--){
                    id--;
                    if(id==-1)
                    id=n-1;
                }
                // cout<<id<<endl;
                res[i]=nums[id];
            }
        }
        return res;
        
    }
};