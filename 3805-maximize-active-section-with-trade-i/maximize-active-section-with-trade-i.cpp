class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
          bool flag = false;
          int o = 0;
          for (auto i:s) {
            if (i == '1')
            o++;
          }
          if (s[0] == '0')
          flag = true;
          vector<int> counts;
          int n = s.size();
          int c = 1, l = counts.size();
          for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1])
            c++;
            else {
                counts.push_back(c);
                c = 1;
            }
          }
          counts.push_back(c);
          l = counts.size();
          int ans = 0, temp;
          for (int i = 0; i < l; i++) {
            // cout<<counts[i]<<" ";
            if (!flag) {
                if (i == 0 || i == l - 1){
                    flag = !flag;
                    continue;
                }
                // cout<< i<< endl;
                temp = counts[i - 1] + counts[i + 1];
                ans = max(ans, temp);
            }
            flag = !flag;
          }
          return ans + o;
        
    }
};