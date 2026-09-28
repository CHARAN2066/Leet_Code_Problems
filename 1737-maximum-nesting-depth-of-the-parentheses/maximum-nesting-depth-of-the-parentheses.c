int maxDepth(char* s) 
{
    int max=0;
    int d=0;
    int n=strlen(s);
    if(n==0)
    max=0;
    else if(n==1&&s[0]=='('&&s[0]==')')
        max==1;
    else{
        for(int i=0;i<n;i++)
            {
            if(s[i]=='(')
                d++;
            if(max<d)
                max=d;
            if(s[i]==')')
                d--;
            }
        }
    return max;
}