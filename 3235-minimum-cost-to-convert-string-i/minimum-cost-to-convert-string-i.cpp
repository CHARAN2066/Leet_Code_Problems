class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        vector<vector<long long int>> ma(26,vector<long long int>(26,(LLONG_MAX/2)));
        int n=original.size();
        for(int i=0;i<26;i++)
        ma[i][i]=0;
        for (int i=0;i<n;i++) 
        {
            ma[original[i]-'a'][changed[i]-'a']=min(ma[original[i]-'a'][changed[i]-'a'],(long long)cost[i]);
        }
        for(int k=0;k<26;k++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    ma[i][j]=min(ma[i][j],(ma[i][k]+ma[k][j]));
                }
            }
        }
        long long int m=source.size();
        long long int ans=0;
        for(int i=0;i<m;i++)
        {
            if(ma[source[i]-'a'][target[i]-'a']==(LLONG_MAX/2))
            return -1;
            ans+=ma[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};