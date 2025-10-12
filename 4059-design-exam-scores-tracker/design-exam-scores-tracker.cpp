class ExamTracker {
public:
    map<long long int,long long int> mp;
    vector<long long int> t;
    long long int last;
    ExamTracker() {
        last=-1;
        
    }
    
    void record(int time, int score) {
        if(last==-1)
        mp[time]=score;
        else
        mp[time]=score+mp[last];
        last=time;
        t.push_back(time);
    }
    
    long long totalScore(int startTime, int endTime) {
        long long int n=t.size();
        long long int mid,low=0,high=n-1;
        long long int ans=0;
        while(low<=high)
        {
            mid=(high+low)/2;
            if(t[mid]<startTime)
            {
                ans=max(ans,t[mid]);
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        long long int t1=mp[ans];
        low=0,high=n-1;
        ans=0;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(t[mid]<=endTime)
            {
                ans=max(ans,t[mid]);
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        long long int t2=mp[ans];
        // cout<<t1<<" "<<t2<<endl;
        return t2-t1;
        // return 0;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */