class Solution {
public:
    int dayOfYear(string date) {
        vector<int> days(12);
        days[0]=31;
        days[1]=28;
        days[2]=31;
        days[3]=30;
        days[4]=31;
        days[5]=30;
        days[6]=31;
        days[7]=31;
        days[8]=30;
        days[9]=31;
        days[10]=30;
        days[11]=31;
        int year=(date[0]-'0')*1000+(date[1]-'0')*100+(date[2]-'0')*10+(date[3]-'0');
        if((year%4==0&&year%100!=0)||(year%400==0)){
            // cout<<"s"<<endl;
            days[1]=29;
        }

        int month=((date[5]-'0')*10)+(date[6]-'0');
        // return year;
        int ans=0;
        for(int i=0;i<month-1;i++)
        ans+=days[i];
        int d=(date[8]-'0')*10+date[9]-'0';
        return ans+d;
    }
};