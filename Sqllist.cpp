#include <iostream>
#include <cstdio> 
#include <cstring>
using namespace std;
int Index(char a[],char b[],int m)
{
    int x,y,i,j,k;
    x=strlen(a);
    i=0;
    while(i<x)
    {
        k=i;
        j=0;
        while(a[k]==b[j]&&k<x&&j<m)
        {
            k++;
            j++;
        }
        if(j==m)
            return i+1;
        if(k==x)
            return 0;
        i++;
    }
    return 0;
}
int main()
{
    char a[50],b[50];
    int n,m;
    scanf("%s %s",a,b);
    m=strlen(b);
    while(Index(a,b,m))
    {
        n=Index(a,b,m);
        for(int j=n+m-1;j<strlen(a);j++)
            a[j-m]=a[j];
        a[strlen(a)-m]='\0';
    }
    printf("%s\n",a);
    return 0;
}
