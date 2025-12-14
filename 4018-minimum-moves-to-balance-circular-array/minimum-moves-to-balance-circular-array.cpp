class Solution {
public:
    long long minMoves(vector<int>& b) {
        long long int n=b.size(),s=-1,e=-1;
        for(int i=0;i<n;i++){
            if(b[i]<0){
                s=i;
                e=i;
            }
        }
        if(s==-1&&e==-1)
            return 0;
        long long int t_s=0;
        for(auto i:b){
            t_s+=i;
        }
        if(t_s<0)
            return -1;
        long long int a=s;
        e=(e+1)%n;
        s=(s-1+n)%n;
        // cout<<e<<" "<<s<<endl;
        long long int steps=1;
        long long int ans=0;
        long long int m;
        while(true){
            if(s!=a)
            {
                m=min(abs(b[s]),abs(b[a]));
                b[a]+=m;
                b[s]-=m;
                ans+=(m*steps);
            }
            if(b[a]>=0)
                return ans;
            if(e!=a)
            {
                m=min(abs(b[e]),abs(b[a]));
                b[a]+=m;
                b[e]-=m;
            // cout<<e<<endl;
                ans+=(m*steps);
            }
            if(b[a]>=0)
                return ans;
            e=(e+1)%n;
            s=(s-1+n)%n;
            steps++;
        }
        return -1;
    }
};