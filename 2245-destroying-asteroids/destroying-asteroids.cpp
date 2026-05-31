class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        long long int n=a.size(),k=mass;
        for(int i=0;i<n;i++){
            if(k>=a[i]){
                k+=a[i];
            }
            else
            return false;
        }
        return true;
        
    }
};