class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int a=1,n=digits.size();
        int s;
        for(int i=n-1;i>=0;i--)
        {
            s=digits[i]+a;
            if(s>=10)
            {
                digits[i]=s%10;;
                a=s/10;
            }
            else 
            {
                digits[i]=s;
                a=0;
            }

        }
        if(a!=0)
        digits.insert(digits.begin(),1,a);
        return digits;
        
    }
};