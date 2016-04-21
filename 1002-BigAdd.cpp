#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void BigAdd(char a[],char b[],char ans[])
{
    int n,m,k,i,j,p=0,r,z;
    n=strlen(a);
    m=strlen(b);
    k=m>n?m:n;
    z=k;
    i=n-1;
    j=m-1;
    while(i>=0||j>=0)
    {
        r=(i>=0?a[i]-'0':0)+(j>=0?b[j]-'0':0)+p;
        p=0;
        ans[k]='0'+r%10;
        p=r/10;
        i--;j--;k--;
    }
    if(p)
    {
        ans[0]='0'+p;
        ans[k+1]='\0';
    }
    else
    {
        for(int i=0;i<z;i++)
            ans[i]=ans[i+1];
        ans[z]='\0';
    }
}
int main()
{
    int n;
    //freopen("test.txt","r",stdin);
    char a[1000],b[1000],ans[1000];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s %s",a,b);
        printf("Case %d:\n",i);
        printf("%s + %s = ",a,b);
        BigAdd(a,b,ans);
        printf("%s\n",ans);
        if(i<n)
             printf("\n");
    }
    return 0;
}
