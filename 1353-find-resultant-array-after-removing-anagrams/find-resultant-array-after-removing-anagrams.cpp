class Solution {
public:
    bool fun(string s1,string s2)
    {
        map<char,int> m1;
        map<char,int> m2;
        for(auto i:s1)
        m1[i]++;
        for(auto i:s2)
        m2[i]++;
        for(char i='a';i<='z';i++)
        {
            if(m1[i]!=m2[i])
            return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        stack<string> st;
        st.push(words[0]);
        string temp;
        int n=words.size();
        for(int i=1;i<n;i++)
        {
            temp=st.top();
            if(!(fun(temp,words[i])))
            {
                st.push(words[i]);
            }
        }
        vector<string> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};