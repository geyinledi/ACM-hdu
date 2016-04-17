#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int next[50];
void GetNext(char a[],int next[])
{
    int j,k;
    j=0;
    k=-1;
    next[0]=-1;
    while(j<strlen(a))
    {
        if(k==-1||a[j]==a[k])
        {
            j++;
            k++;
            next[j]=k;
        }
        else
            k=next[k];
    }
    /*for(int i=0;i<j;i++)
        cout<<next[i]<<" ";
    cout<<endl;*/
}
int KMP_Index(char s[],int pos,char a[],int next[])
{
    int i,j,m,n;
    i=pos-1;
    j=0;
    n=strlen(s);
    m=strlen(a);
    //cout<<strlen(s)<<" "<<strlen(a)<<endl;
    while(i<n&&j<m)
    {

        if(j==-1||s[i]==a[j])
        {
            i++;
            j++;
            //cout<<i<<endl;
        }
        else
            j=next[j];
    }
    cout<<i<<" "<<j<<endl;
    if(j>=m)
        return i-m+1;
    else
        return -1;
}
int main()
{
    char s[50],a[50];
    int n,m;
    scanf("%s %s",s,a);
    GetNext(a,next);
    m=strlen(a);
   // cout<<KMP_Index(s,1,a,next)<<endl;
    while(KMP_Index(s,1,a,next)!=-1)
    {
        n=KMP_Index(s,1,a,next);
 //       cout<<n<<" ";
        for(int i=n+m-1;i<strlen(s);i++)
            s[i-m]=s[i];
        s[strlen(s)-m]='\0';
 //       cout<<"1"<<endl;
    }
    printf("%s\n",s);
}
