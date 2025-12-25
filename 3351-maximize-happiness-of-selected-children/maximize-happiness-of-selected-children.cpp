class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<long long> pq;
        for(auto i:happiness){
            pq.push(i);
        }
        long long a=0,ans=0;
        for(int i=0;i<k;i++){
            if(pq.empty())
            return ans;
            if(pq.top()==0)
            return ans;
            ans+=(max((pq.top()-i),a));
            pq.pop();
        }
        return ans;
        
    }
};