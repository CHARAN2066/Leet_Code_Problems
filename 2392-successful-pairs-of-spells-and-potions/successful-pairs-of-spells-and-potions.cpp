class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

        sort(potions.begin(),potions.end());
        double a;
        int id,left,right,target,mid,ans;
        int m=potions.size();
        vector<int> res;
        for(auto i:spells)
        {
            a=static_cast<double>(success)/static_cast<double>(i);
            id=-1;
            left=0;
            right=m-1;
            ans=-1;
            while(left<=right)
            {
                mid=(right+left)/2;

                if(potions[mid]>=ceil(a))
                {
                    ans=mid;
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
            if(ans==-1)
            res.push_back(0);
            else
            res.push_back(m-ans);
            
        }
        return res;
        
    }
};