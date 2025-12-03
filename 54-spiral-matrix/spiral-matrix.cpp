class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> ans;
        int n=arr.size();
        int m=arr[0].size();
        // cout<<n<<" "<<m<<endl;
        
        int a=0,b=0;
        // cout<<x<<" "<<y<<endl;
        while(true){
            // cout<<a<<b<<endl;
            for(int i=a;i<m-a;i++)
            ans.push_back(arr[a][i]);
            if(ans.size()==n*m)
            break;
            for(int i=b+1;i<n-b;i++)
            ans.push_back(arr[i][m-b-1]);
            if(ans.size()==n*m)
            break;
            for(int i=m-a-2;i>=a;i--)
            ans.push_back(arr[n-a-1][i]);
            if(ans.size()==n*m)
            break;
            for(int i=n-b-2;i>=b+1;i--)
            ans.push_back(arr[i][b]);
            if(ans.size()==n*m)
            break;
            a++;
            b++;
            // break;
        }
        return ans;
        
    }
};