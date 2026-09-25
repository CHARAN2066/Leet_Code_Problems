class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), c = 1, i = 0, j = 1, r;
        vector<char> temp;
        if (n == 1)
        return 1;
        while (j < chars.size()) {
            // cout<<i<<" "<<j<<endl;
            if (chars[i] == chars[j]) {
                chars.erase(chars.begin() + j); 
                c++;
                // j++;
            }
            else {
                if (c == 1) {
                    i = j;
                    j++;
                }
                else {
                    temp.clear();
                    while (c > 0) {
                        r = c % 10;
                        temp.push_back(r + '0');
                        c = c / 10;
                    }
                    reverse(temp.begin(), temp.end());
                    for (auto k:temp) {
                        chars.insert(chars.begin() + j, k);
                        j++;
                    }
                    i = j;
                    j++;
                    c = 1;   
                }
            }
        }
        if (c == 1)
        return chars.size();
        temp.clear();
        while (c > 0) {
            r = c % 10;
            temp.push_back(r + '0');
            c = c / 10;
        }
        reverse(temp.begin(), temp.end());
        for (auto k:temp) {
            chars.insert(chars.begin() + j, k);
            j++;
        }
        i = j;
        j++;
        return chars.size();
    }
};