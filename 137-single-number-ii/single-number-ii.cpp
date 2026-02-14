class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<pair<int,int>> count(33,{0,0});
        long long int r,t;
        pair<int,int> ne;
        vector<int> binary;
        for(auto i:nums){
            t=abs(static_cast<long long >(i));
            binary.clear();
            while(t>0){
                r=t%2;
                binary.push_back(r);
                t=t/2;
            }
            reverse(binary.begin(),binary.end());
            while(binary.size()<33)
            binary.insert(binary.begin(),0);
            for(int j=0;j<binary.size();j++){
                if(binary[j]==0){
                    count[32-j].first++;
                }
                else{
                    count[32-j].second++;
                }
            }
            if(i<0)
            ne.second++;
            else
            ne.first++;
        }
        vector<int> ans;
        for(auto i:count){
            // cout<<i.first<<" "<<i.second<<endl;
            if(i.first%3!=0)
            ans.push_back(0);
            else if(i.second%3!=0)
            ans.push_back(1);
        }
        long long int res=0;
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
        {

            // cout<<ans[i]<<" ";
            if(i==0)
            continue;
            res+=(ans[i]*(1<<(32-i)));
        }
        if(ne.first%3!=0)
        return res;
        else
        return -res;
        
    }
};