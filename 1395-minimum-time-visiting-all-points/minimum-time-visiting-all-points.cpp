class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int a,b,ans=0,n=points.size();
        for(int i=0;i<n-1;i++){
            a=abs(points[i][0]-points[i+1][0]);
            b=abs(points[i][1]-points[i+1][1]);
            ans+=max(a,b);
        }
        return ans;
    }
};