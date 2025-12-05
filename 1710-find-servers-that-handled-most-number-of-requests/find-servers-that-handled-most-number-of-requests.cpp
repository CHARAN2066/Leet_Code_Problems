class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n=arrival.size();
        vector<int> ans(k,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        set<int> a;
        // vector<int> a;
        vector<int> busy(k);
        for(int i=0;i<min(k,n);i++){
            ans[i]++;
            pq.push({(load[i]+arrival[i]),i});
            busy[i]=load[i]+arrival[i];
        }
        for(int i=min(k,n);i<n;i++)
        {
            while(!pq.empty()){
                if(pq.top().first>(arrival[i]))
                break;
                a.insert(pq.top().second);
                pq.pop();
            }
            if(a.size()==0)
            continue;
            auto it=a.lower_bound(i%k);
            int id;
            if(it==a.end())
            it=a.begin();
            pq.push({(load[i]+arrival[i]),*it});
            // busy[*it]=load[i]+arrival[i];
            ans[*it]++;
            a.erase(it); 
            // cout<<endl;
            // cout<<id<<endl;
        }
        int m=0;
        n=ans.size();
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
            m=max(m,ans[i]);
        }
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(ans[i]==m)
            res.push_back(i);
        }
        return res;
        
    }
};