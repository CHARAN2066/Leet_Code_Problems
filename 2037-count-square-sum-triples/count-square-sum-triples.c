int countTriples(int n) 
{
    int c=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            float a=sqrt(i*i+j*j);
            if((a<=n)&&(ceil(a)==floor(a)))
            c++;
        }
    }
    return c*2;
}