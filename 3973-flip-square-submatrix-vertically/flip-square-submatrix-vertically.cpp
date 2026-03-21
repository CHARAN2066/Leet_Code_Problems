class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int a,b,n=grid.size(),m=grid[0].size();
        for(int i=y;i<y+k;i++){
            a=x,b=x+k-1;
            while(a<b){
                swap(grid[a][i],grid[b][i]);
                a++;
                b--;
            }
        }
        return grid;
    }
};