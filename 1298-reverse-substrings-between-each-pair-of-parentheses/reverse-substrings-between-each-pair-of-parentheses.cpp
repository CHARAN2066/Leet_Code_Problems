class Solution {
public:
    string reverseParentheses(string s) 
    {
        int a,n=s.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            st.push(i);
            else if(s[i]==')')
            {
                a=st.top();
                reverse(s.begin()+a,s.begin()+i);
                st.pop();
            }
        }
        auto i=s.begin();
        while(i!=s.end())
        {
            if(*i=='('||*i==')')
            s.erase(i);
            else
            i++;
        }
        return s;
        
    }
};