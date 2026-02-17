class Solution {
public:
    vector<int> hours={8,4,2,1};
    vector<int> minitues={32,16,8,4,2,1};
    void fun1(int i,int size,int s,vector<int> &ans,int a){
        if(i==4)
        {
            if(size==a)
            {
                ans.push_back(s);
            }
            return;
        }
        // cout<<i<<" "<<size<<endl;
        
        fun1(i+1,size,s+hours[i],ans,a+1);
        fun1(i+1,size,s,ans,a);
        return;
    }
    void fun2(int i,int size,int s,vector<int> &ans2,int a){
        if(i==6)
        {
            if(size==a)
            {
                ans2.push_back(s);
            }
            return;
        }
        // cout<<i<<" "<<size<<endl;
        
        fun2(i+1,size,s+minitues[i],ans2,a+1);
        fun2(i+1,size,s,ans2,a);
        return;
    }
    vector<string> readBinaryWatch(int n) {
        int h,m;
        vector<int> ans;
        vector<int> ans2;
        fun1(0,2,0,ans,0);
        fun2(0,2,0,ans2,0);
        vector<string> res;
        string temp;
        for(int i=0;i<=4&&i<=n;i++){
            m=n-i;
            temp="";
            vector<int> ans;
            vector<int> ans2;
            fun1(0,i,0,ans,0);
            fun2(0,m,0,ans2,0); 
            for(auto i:ans)
            {
                temp="";
                for(auto j:ans2){
                    if(i>=12||j>=60)
                    continue;
                    else
                    {
                        
                        temp="";
                        temp+=to_string(i);
                        temp+=":";
                        if(j<10)
                        temp+="0";
                        temp+=to_string(j);
                        res.push_back(temp);
                    }
                }
            }
        }
        return res;
    }
};