class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> ans;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        if(i==j||j==k||k==l||l==i||i==k||j==l)
                        continue;
                        if((words[i][0]==words[j][0])&&(words[i][3]==words[k][0])&&(words[l][0]==words[j][3])&&(words[l][3]==words[k][3]))
                        ans.push_back({words[i],words[j],words[k],words[l]});
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};