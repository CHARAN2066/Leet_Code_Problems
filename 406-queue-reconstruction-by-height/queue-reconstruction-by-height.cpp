class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end());
        int n=people.size(),c=0;
        vector<vector<int>> ans(n,{-1,-1});
        for(int i=0;i<n;i++){
            c=0;
            // cout<<people[i][0]<<" "<<people[i][1]<<endl;
            for(int j=0;j<n;j++){
                if(c==people[i][1]){
                    if(ans[j][0]==-1){
                        ans[j][0]=people[i][0];
                        ans[j][1]=people[i][1];
                    }
                }
                if(ans[j][0]==-1||ans[j][0]==people[i][0])
                c++;
            }
        }
        return ans;
       
    }
};