class Solution {
public:
    int check(vector<vector<int>>& grid,int r,int c,int a,int n,int m){
        int b=0,s=0;
        for(int i=c;i<c+a;i++)
        {
            b+=grid[r][i];
        }
        // cout<<b<<" ";
        for(int i=r;i<r+a;i++){
            s=0;
            for(int j=c;j<c+a;j++){
                s+=grid[i][j];
            }
            // cout<<s<<" ";
            if(s!=b)
            return 1;
        }
        s=0;
        for(int i=c;i<c+a;i++){
            s=0;
            for(int j=r;j<r+a;j++){
                s+=grid[j][i];
            }
            if(s!=b)
            return 2;
        }
        int d1=0;
        for(int i=0;i<a;i++){
            d1+=grid[r+i][c+i];
        }
        if(d1!=b)
        return 3;
        int d2=0;
        for(int i=0;i<a;i++){
            d2+=grid[r+i][c+a-i-1];
        }
        // cout<<d2<<" ";
        if(d2!=b)
        return 4;
        return 5;
    }

    // 8 1 6
    // 3 5 7
    // 4 9 2
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int a=min(n,m),ans=1;
        for(int i=2;i<=a;i++){
            for(int j=0;j<n-i+1;j++){
                for(int k=0;k<m-i+1;k++){
                    // cout<<i<<" "<<check(grid,j,k,i,n,m)<<endl;
                    if(check(grid,j,k,i,n,m)==5)
                    ans=i;
                }
            }
        }
        return ans;
    }
};