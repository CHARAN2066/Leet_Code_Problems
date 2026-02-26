class Solution {
public:
    bool isOperator(char o){
        if(o=='+'||o=='-'||o=='*')
        return true;
        return false;
    }
    vector<int> fun(string e){
        // cout<<e<<endl;
        int n=e.size(),cal;
        vector<int> a,b,ans;
        if(n==2){
            return {(e[0]-'0')*10+(e[1]-'0')};
        }
        if(n==1)
        {
            // cout<<"s";
            return {(e[0]-'0')};
        }
        bool flag=false;
        for(int i=0;i<n;i++){
            if(isOperator(e[i])){
                // cout<<e[i]<<endl;
                a=fun((e.substr(0,i)));
                b=fun((e.substr(i+1)));
                for(auto l:a){
                    for(auto k:b){
                        cal=0;
                        if(e[i]=='+'){
                            cal=l+k;
                        }
                        else if(e[i]=='-'){
                            cal=l-k;
                        }
                        else{
                            cal=l*k;
                        }
                        ans.push_back(cal);
                    }
                }
            }
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string e) {
        vector<int> ans;
        ans=fun(e);
        return ans;
    }
};