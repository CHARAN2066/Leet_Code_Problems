class Solution {
public:
    vector<int> findFactor(long long n){
        int a=0,b=0,c=0;
        while(n%2==0){
            a++;
            n/=2;
        }
        while(n%3==0){
            b++;
            n/=3;
        }
        while(n%5==0){
            c++;
            n/=5;
        }
        return {a,b,c};
    }
    int countSequences(vector<int>& nums, long long k) {
        int n=nums.size();
        vector<map<pair<pair<int,int>,int>,int>> dp(n);
        int a=0,b=0,c=0;
        vector<int> t;
        vector<int> t2;
        t=findFactor(nums[0]);
        vector<int> temp=findFactor(k);
        long long int ac=(pow(2,temp[0])*pow(3,temp[1])*pow(5,temp[2]));
        // cout<<ac<<endl;
        if(ac!=k)
        return 0;
        // cout<<endl;
        dp[0][{{a-t[0],b-t[1]},c-t[2]}]++;
        dp[0][{{a+t[0],b+t[1]},c+t[2]}]++;
        dp[0][{{0,0},0}]++;
        // cout<<dp[0][{{0,0},0}]<<endl;
        for(int i=1;i<n;i++){
            t.clear();
            t2.clear();
            t=findFactor(nums[i]);
            // cout<<"s";
            for(auto j:dp[i-1]){
                t2.clear();
                t2.push_back(j.first.first.first);
                t2.push_back(j.first.first.second);
                t2.push_back(j.first.second);
                // for(auto l:t2) cout<<l<<" ";
                // cout<<endl;
                dp[i][{{t2[0],t2[1]},t2[2]}]+=j.second;
                dp[i][{{t2[0]-t[0],t2[1]-t[1]},t2[2]-t[2]}]+=j.second;
                dp[i][{{t2[0]+t[0],t2[1]+t[1]},t2[2]+t[2]}]+=j.second;
            }
        }
        // for(auto i:dp[n-1]){
        //     cout<<i.first.first.first<<" ";
        //     cout<<i.first.first.second<<" ";
        //     cout<<i.first.second<<" ";
        //     cout<<endl;
        // }
        vector<int> o=findFactor(k);
        return dp[n-1][{{o[0],o[1]},o[2]}];
    }
};