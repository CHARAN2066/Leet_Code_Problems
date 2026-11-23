class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        double root = sqrt(n);
        int a, r = ceil(root), s, levels = 0;
        q.push(n);
        vector<bool> visted(n + 1, false);
        while (!q.empty()) {
            s = q.size();
            for (int i = 0; i < s; i++) {
                a = q.front();
                q.pop();
                if (a < 0)
                continue;
                if (a >= 0 && visted[a])
                continue;
                visted[a] = true;
                if (a == 0)
                return levels;
                for (int j = 1; j <= r; j++) {
                    // if (visted[a - (j * j)])
                    q.push(a - (j * j));
                }
            }
            levels++;
        }
        return -1;
    }
};