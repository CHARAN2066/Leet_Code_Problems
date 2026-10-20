class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string res = "123450";
        queue<vector<vector<int>>> q;
        map<vector<vector<int>>, bool> visted;
        q.push(board);
        // visted[board] = true;
        int si = 0, zi, zj, k, levels = 0;
        vector<vector<int>> temp;
        while (!q.empty()) {
            si = q.size();
            // cout<<si<<endl;
            for (int a = 0; a < si; a++) {
                temp = q.front();
                q.pop();
                k  = 0;
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (temp[i][j] == 0) {
                            zi = i;
                            zj = j;
                        }
                        if (temp[i][j] == (res[k] - '0'))
                        k++;
                    }
                }
                if (k == 6)
                return levels;
                if (visted[temp])
                continue;
                visted[temp] = true;
                if (zi + 1 < 2) {
                    swap(temp[zi][zj], temp[zi + 1][zj]);
                    q.push(temp);
                    swap(temp[zi][zj], temp[zi + 1][zj]);
                }
                if (zj + 1 < 3) {
                    swap(temp[zi][zj], temp[zi][zj + 1]);
                    q.push(temp);
                    swap(temp[zi][zj], temp[zi][zj + 1]);
                }
                if (zi - 1 >= 0) {
                    swap(temp[zi][zj], temp[zi - 1][zj]);
                    q.push(temp);
                    swap(temp[zi][zj], temp[zi - 1][zj]);
                }
                if (zj - 1 >= 0) {
                    swap(temp[zi][zj], temp[zi][zj - 1]);
                    q.push(temp);
                    swap(temp[zi][zj], temp[zi][zj - 1]);
                }
            }
            levels++;
        }
        return -1;
    }
};