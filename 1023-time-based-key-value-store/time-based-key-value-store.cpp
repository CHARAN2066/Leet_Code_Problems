class TimeMap {
public:
    map<string,vector<pair<string,int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        int n=mp[key].size();
        int low=0,high=n-1,mid;
        string ans="";
        while(low<=high){
            mid=(low+high)/2;
            if(mp[key][mid].second<=timestamp){
                ans=mp[key][mid].first;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */