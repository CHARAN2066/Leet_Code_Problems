class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int l=0,r=n-1,mid,ans=-1;
        while(l<=r){
            mid=(l+r)/2;
            // cout<<mid<<endl;
            if(letters[mid]>target){
                ans=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        if(ans==-1)
        return letters[0];
        return letters[ans];
        
    }
};