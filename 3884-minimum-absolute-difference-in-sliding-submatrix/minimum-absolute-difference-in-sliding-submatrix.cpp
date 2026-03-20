class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size(),s1=n-k+1,s2=m-k+1,s,res=INT_MAX;
        vector<vector<int>> ans(s1,vector<int>(s2));
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.clear();
                for(int l=i;l<i+k&&l<n;l++){
                    for(int o=j;o<j+k&&o<m;o++){
                        temp.push_back(grid[l][o]);
                    }
                }
                if(temp.size()<k*k)
                continue;
                else{
                    sort(temp.begin(),temp.end());
                    s=temp.size();
                    res=INT_MAX;
                    for(int I=0;I<s-1;I++){
                        if(temp[I]==temp[I+1])
                        continue;
                        res=min(res,abs(temp[I]-temp[I+1]));
                    }
                    if(res==INT_MAX)
                    ans[i][j]=0;
                    else
                    ans[i][j]=res;
                }
            }
        }
        return ans;
    }
};