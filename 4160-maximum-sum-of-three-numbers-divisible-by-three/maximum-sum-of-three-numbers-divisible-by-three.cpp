class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> z,o,t;
        for(auto i:nums){
            if(i%3==1)
            o.push_back(i);
            if(i%3==2)
            t.push_back(i);
            if(i%3==0)
            z.push_back(i);
        }
        sort(o.begin(),o.end(),greater<int>());
        sort(t.begin(),t.end(),greater<int>());
        sort(z.begin(),z.end(),greater<int>());
        int temp=0,ans=0;
        if(z.size()!=0&&o.size()!=0&&t.size()!=0)
        temp+=(z[0]+o[0]+t[0]);
        ans=max(ans,temp);
        if(t.size()>=3){
           temp=0;
            for(int i=0;i<3;i++)
            temp+=t[i];
            ans=max(ans,temp);
        }
        if(z.size()>=3){
           temp=0;
            for(int i=0;i<3;i++)
            temp+=z[i];
            ans=max(ans,temp);
        }
        if(o.size()>=3){
           temp=0;
            for(int i=0;i<3;i++)
            temp+=o[i];
            ans=max(ans,temp);
        }
        return ans;
    }
};