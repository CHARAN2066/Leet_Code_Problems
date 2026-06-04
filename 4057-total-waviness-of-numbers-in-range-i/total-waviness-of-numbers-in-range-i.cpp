class Solution {
public:
    int fun(int a){
        vector<int> digits;
        int r;
        while(a>0){
            r=a%10;
            digits.push_back(r);
            a=a/10;
        }
        reverse(digits.begin(),digits.end());
        int s=digits.size(),ans=0;
        for(int i=1;i<s-1;i++){
            if((digits[i]>digits[i+1]&&digits[i]>digits[i-1])||(digits[i]<digits[i+1]&&digits[i]<digits[i-1]))
            ans++;
        }
        return ans++;
    }
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
            if(i<=99)
            continue;
            ans+=fun(i);
        }
        return ans;
        
    }
};