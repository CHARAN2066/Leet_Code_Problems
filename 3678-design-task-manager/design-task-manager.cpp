class TaskManager {
public:
    priority_queue<pair<int,int>> pq;
    map<int,pair<int,int>> mp;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto i:tasks)
        {
            pq.push({i[2],i[1]});
            mp[i[1]]={i[0],i[2]};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority,taskId});
        mp[taskId]={userId,priority};
    }
    
    void edit(int taskId, int newPriority) {
        pq.push({newPriority,taskId});
        mp[taskId].second=newPriority;
    }
    
    void rmv(int taskId) {
        mp[taskId]={-1,-1};
    }
    
    int execTop() {
        int ans;
        while(!pq.empty())
        {
            int p=pq.top().first;
            int t=pq.top().second;
            pq.pop();
            if(mp[t].second==p)
            {
                ans=mp[t].first;
                mp[t]={-1,-1};
                return ans;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */