class Solution {
public:
    int numWaterBottles(int n, int ne) 
    {
        int a,ans=n;
        while(1)
        {
            if(n<ne)
            return ans;
            // cout<<n<<" ";
            a=n/ne;
            ans+=a;
            n=n-(ne*a)+a;
        }
        return -1;
    }
};