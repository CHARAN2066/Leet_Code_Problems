class Solution {
public:
    bool check(string a, string b) {
        if (a == b)
        return 0;
        int n = a.size(), c = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i])
            c++;
        }
        return c == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> adj;
        int n = wordList.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (check(wordList[i], wordList[j])){
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (check(beginWord, wordList[i])) {
                adj[beginWord].push_back(wordList[i]);
                adj[wordList[i]].push_back(beginWord);
            }
        }
        int ans = 0, s;
        queue<string> q;
        q.push(beginWord);
        map<string, bool> visted;
        visted[beginWord] = true;
        string temp;
        while (!q.empty()) {
            s = q.size();
            ans++;
            for (int j = 0; j < s; j++) {
                temp = q.front();
                if (temp == endWord)
                return ans;
                q.pop();
                for (auto i:adj[temp]) {
                    if (visted[i])
                    continue;
                    q.push(i);
                    visted[i] = true;
                }
            }
        }
        return 0;
    }
};