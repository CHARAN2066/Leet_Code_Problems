class Solution {
public:
    double dist(int x, int y, int xCenter, int yCenter) {
        double a = (x - xCenter) * (x - xCenter);
        double b = (y - yCenter) * (y - yCenter);
        double ans = sqrt(a + b);
        return ans;
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (dist(i, j, xCenter, yCenter) <= radius) {
                    // cout<<i<<" "<<j<< endl;
                    return true;
                }
            }
        }
        return false;
    }
};