class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> l;
        vector<string> d;
        bool flag;
        for(auto i:logs){
            flag=true;
            for(auto j:i){
                if(j==' ')
                {
                    flag=false;
                    continue;
                }
                if(flag)
                continue;
                // cout<<j<<" ";
                if(j<='9'&&j>='0')
                {
                    d.push_back(i);
                    break;
                }
                else
                {
                    l.push_back(i);
                    break;
                }
            }
        }
        vector<pair<string,string>> words;
        string t,p;
        int n=l.size();
        map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            p="";
            t="";
            flag=true;
            for(auto j:l[i])
            {
                if(flag&&j==' ')
                {
                    
                    flag=false;
                    continue;
                }
                if(flag)
                {p.push_back(j);
                continue;}
                t.push_back(j);
            }
            mp[p+t]=i;
            words.push_back({t,p});
        }
        // vector
        sort(words.begin(),words.end());
        // for(auto i:words)
        // {
        //     cout<<i.second<<i.first<<endl;
        // }
        vector<string> ans;
        for(auto i:words)
        ans.push_back(l[mp[i.second+i.first]]);
        for(auto i:d)
        ans.push_back(i);
        // cout<<endl;
        return ans;
    }
};