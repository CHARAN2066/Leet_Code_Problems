class Solution {
public:
    int number(string t){
        int ans=0,n=t.size();
        for(int i=0;i<n;i++){
            ans+=(t[i]-'0')*(1<<(n-i-1));
        }
        return ans;
    }
    bool hasAllCodes(string s, int k) {
        int v=1<<(k),n=s.size();
        // cout<<v<<endl;
        // v=v-1;
        vector<int> a(v,0);
        // cout<<number("100");
        int temp=0;
        string t;
        if(k>n)
        return false;
        for(int i=0;i<k;i++){
            t.push_back(s[i]);
        }
        // cout<<number(t)<<endl;
        a[number(t)]=1;
        // cout<<t<<endl;
        for(int i=k;i<n;i++){
            t.erase(t.begin());
            t.push_back(s[i]);
            // cout<<number(t)<<endl;
            a[number(t)]=1;
        }
        // cout<<"s"<<endl;
        for(auto i:a){
            // cout<<i<<endl;
            if(i==0)
            return false;
        }
        return true;
    }
};