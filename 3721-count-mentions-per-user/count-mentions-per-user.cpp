class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        int s=events.size();
        int si;
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
        if(stoi(a[1])==stoi(b[1]))
        return a[0]>b[0];
        else
        return stoi(a[1]) < stoi(b[1]); 
        });
        // for(int i=0;i<events.size();i++)
        // {
        //     for(int j=0;j<events[i].size();j++)
        //     cout<<events[i][j]<<" ";
        //     cout<<endl;
        // }
        vector<int> ans(n,0);
        vector<int> offline(n,0);
        int size=0,num=0;
        bool flag=false;
        int time=0;
        for(int i=0;i<s;i++)
        {
            if(events[i][0]=="MESSAGE")
            {
                size=events[i][2].size();
                if(events[i][2]=="ALL")
                {
                    for(int j=0;j<n;j++)
                    ans[j]+=1;
                    continue;
                }
                time=0;
                for(int k=0;k<events[i][1].size();k++)
                {
                    time=time*10+(events[i][1][k]-'0');
                }
                if(events[i][2]=="HERE")
                {
                    for(int j=0;j<n;j++)
                    {
                        if(offline[j]<=time)
                        ans[j]+=1;
                    }
                    continue;
                }
                for(int j=0;j<size;j++)
                {
                    if(events[i][2][j]=='i'||events[i][2][j]=='d'||events[i][2][j]==' ')
                    {
                        if(flag)
                        {
                            ans[num]++;
                            // cout<<num<<" ";
                        }
                        num=0;
                        flag=false;
                        continue;
                    }
                    else
                    {
                        num=num*10+(events[i][2][j]-'0');
                        flag=true;
                    }   
                }
                if(flag)
                {
                    ans[num]++;
                    flag=false;
                    // cout<<num<<" ";
                }
            }
            if(events[i][0]=="OFFLINE")        
            {
                time=0;
                for(int k=0;k<events[i][1].size();k++)
                {
                    time=time*10+(events[i][1][k]-'0');
                }
                int id=0;
                for(int k=0;k<events[i][2].size();k++)
                {
                    id=id*10+(events[i][2][k]-'0');
                }
                // ans[id]=0;
                offline[id]=time+60;
            }            
        }
        return ans;    
    }
};