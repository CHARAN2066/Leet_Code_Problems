class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        long long int n=nums.size(),ans=0;
        int c=0;
        for(auto i:nums){
            c=0;
            for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    if(j==(i/j))
                    {
                        c++;
                    }
                    else
                    c+=2;
                }
            }
            if(c==4)
            {
                for(int j=1;j*j<=i;j++){
                    if(i%j==0){
                        if(j==(i/j))
                        {
                            ans+=j;
                        }
                        else
                        {
                            ans+=j;
                            ans+=(i/j);
                        }
                    }
                }
            }
        }
        return ans;
    }
};