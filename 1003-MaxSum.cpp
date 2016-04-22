#include <iostream>
#include <cstdio>
using namespace std;
int a[100002];
int main()
{
    int n,m,flag=0,flag1=0,flag2=0;
    long long ans=0,sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        for(int j=0;j<m;j++)
            scanf("%d",&a[j]);
        ans=sum=a[0];
        for(int j=1;j<m;j++)
        {
            if(ans+a[j]<a[j])
            {
                flag1=j;
                ans=a[j];
            }
            else
                ans=ans+a[j];
            if(ans>sum)
            {
                flag2=j;
                flag=flag1;
                sum=ans;
            }
        }
        printf("Case %d:\n",i+1);
        printf("%lld %d %d\n",sum,flag+1,flag2+1);
        if(i<n-1)
            printf("\n");
        flag=0;flag1=0;flag2=0;
        sum=0;ans=0;
    }
    return 0;
}
