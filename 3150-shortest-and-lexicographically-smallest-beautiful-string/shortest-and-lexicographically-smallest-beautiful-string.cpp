class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size(), o = 0;
        string a, b; 
        for (int i = 0; i < 200; i++)
        a.push_back('1');
        for (int i = 0; i < n; i++) {
            o = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1')
                o++;
                b.push_back(s[j]);
                if (o == k)
                {
                    if (a.size() > b.size())
                    a = b;
                    else if(a.size() == b.size())
                    a = min(a, b);
                    // cout<< a<< endl;
                    break;
                }
            }
            // cout<< a<< " "<< b<< endl;
            b = "";
        }
        if (a.size() == 200)
        return "";
        return a;
    }
};