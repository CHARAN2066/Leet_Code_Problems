class Solution {
public:
    int minimumCost(vector<int>& arr) {
        int n=arr.size(),a=arr[0],m1=INT_MAX,id1;
        for(int i=1;i<n;i++){
            if(m1>arr[i]){
                m1=arr[i];
                id1=i;
            }
        }
        int m2=INT_MAX,id2;
        for(int i=1;i<n;i++){
            if(i==id1)
            continue;
            if(m2>arr[i]){
                m2=arr[i];
                id2=i;
            }
        }
        return a+m1+m2;

    }
};