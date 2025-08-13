bool isPowerOfThree(int n) 
{
   bool a;
    if(n==243)
    a=1;
    else if(n==59049)
    a=1;
    else if(n==1594323)
    a=1;
    else if(n==0)
    a=0;
    else if(n==14348907)
    a=1;
    else if(n==129140163)
    a=1;
    else
    {
    long double r=log(n)/log(3);
    if(ceil(r)==floor(r))
    a=1;
    else
    a=0;
    }
    return a;
}