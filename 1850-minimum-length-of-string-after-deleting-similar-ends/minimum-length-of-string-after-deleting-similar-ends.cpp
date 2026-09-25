class Solution {
public:
    int minimumLength(string s) {
        int n = s.size(), i = 0, j = n - 1;
        char curr;
        while (i < j) {
            if (s[i] != s[j])
            break;
            curr = s[i];
            while(s[i] == curr) {
                i++;
            }
            while(i < j && s[j] == curr) {
                j--;
            }
        }
        for (int k = i; k <= j && k < n; k++) {
            cout<<s[k];
        }
        cout<<endl;
        return (j - i + 1);
    }
};