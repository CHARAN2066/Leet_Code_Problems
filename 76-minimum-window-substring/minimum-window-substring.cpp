class Solution {
public:
    bool check(map<char,int> &temp,map<char,int> &mp){
        // cout<<"s"<<endl;
        for(char i='a';i<='z';i++){
            if(temp[i]>=mp[i])
            continue;
            else
            return false;
        }
        for(char i='A';i<='Z';i++){
            if(temp[i]>=mp[i])
            continue;
            else
            return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        map<char,int> temp;
        map<char,int> mp;
        string res,fires="";
        for(auto i:t){
            mp[i]++;
        }
        int ans=INT_MAX;
        int low=0,n=s.size();
        for(int end=0;end<n;end++){
            temp[s[end]]++;
            res.push_back(s[end]);
            while(check(temp,mp)&&low<=end){
                if(ans>(end-low+1)){
                    ans=(end-low+1);
                    fires=res;
                }
                res.erase(0,1);
                // cout<<low<<" "<<end<<endl;
                temp[s[low]]--;
                low++;
            }
        }

        // cout<<ans<<endl;
        return fires;
    }
};