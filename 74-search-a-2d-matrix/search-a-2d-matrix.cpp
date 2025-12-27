class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int l=0,h=n*m-1,mid,row,col;
        while(l<=h){
            mid=(l+h)/2;
            row=mid/m;
            col=mid%m;
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return false;
        
    }
};