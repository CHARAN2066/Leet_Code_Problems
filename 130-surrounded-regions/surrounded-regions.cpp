class Solution {
public:
    bool helper(vector<vector<char>> &board,int i,int j,int n,int m,vector<vector<bool>> &visted){
        if(i>=n||j>=m||i<0||j<0)
        return true;
        if(board[i][j]=='X')
        return true;
        if(i==0||j==0||i==n-1||j==m-1)
        {
            return false;
        }
        if(visted[i][j])
        return true;
        visted[i][j]=true;
        bool a=helper(board,i+1,j,n,m,visted);
        bool b=helper(board,i,j+1,n,m,visted);
        bool c=helper(board,i-1,j,n,m,visted);
        bool d=helper(board,i,j-1,n,m,visted);
        return a&b&c&d;
    }
    
    void helper2(vector<vector<char>> &board,int i,int j,int n,int m){
        if(i>=n||j>=m||i<0||j<0)
        return;
        if(board[i][j]=='X')
        return;
        board[i][j]='X';
        helper2(board,i+1,j,n,m);
        helper2(board,i,j+1,n,m);
        helper2(board,i-1,j,n,m);
        helper2(board,i,j-1,n,m);
        return;
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    vector<vector<bool>> visted(n,vector<bool> (m,false));
                    if(helper(board,i,j,n,m,visted)){
                        cout<<i<<j<<endl;
                        helper2(board,i,j,n,m);
                    }
                }
            }
        }
        return;
    }
};