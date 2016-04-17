#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
using namespace std;
void quick_sort(int a[],int left,int right)
{
    int l,r,x,t;
    if(left<right)
    {
        l=left;
        r=right;
        x=a[(right+left)/2];
        while(l<r)
        {
           // cout<<"1"<<endl;
            while(l<r&&a[r]>x)
            {
                r--;
            }
            while(l<r&&a[l]<x)
            {
                l++;
            }
            if(l<r)
            {
                t=a[l];
                a[l]=a[r];
                a[r]=t;
                l++;
                r--;
            }
        }
        quick_sort(a,left,l-1);
        quick_sort(a,r+1,right);
    }
}
int main()
{
    int a[]={2,3,1,7,6,10,8,9};
    quick_sort(a,0,7);
    for(int i=0;i<8;i++)
        printf("%3d",a[i]);
    printf("\n");
    return 0;
}
