#include <stdio.h>
int takefork(int i,int left,int right,int s[])
{
    if(s[i]==1&&s[left]!=2&&s[right]!=2)
    {
        s[i]=2;
        printf(" philosopher %d can eat\n",i);
    }
    return 0;
}
int main()
{
    int n,left,right;
    scanf("%d",&n);
    int s[6];
    for(int i=1;i<=n;i++)
    {
        s[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]==0)
        {
            s[i]=1;
            printf(" the philosopher %d falls hungry\n\n",i);
            left=(i+4)%5;
            right=(i+1)%5;
            takefork(i,left,right,s);
            if(s[i]==2)
            {
                printf(" Eating in process....\n");
                s[i]=0;
                printf(" philosopher %d completed its works\n\n",i);
                takefork(left,(left+4)%5,(left+1)%5,s);
                takefork(right,(right+4)%5,(right+1)%5,s);
            }
        }
    }
}
