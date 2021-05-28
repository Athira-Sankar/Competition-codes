#include<iostream>
using namespace std;
int t,n,b,a[10000];
void sort()
{
    int i,j,temp;
    for(i=0;i<n;i++)
    for(j=i+1;j<n-i-1;j++)
    {
        if(a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
    for(i=0;i<n;i++)
        cout<<a[i];
}
void inpfin()
{
    int i,l=0;
    do
    {

        cin>>n;
        cin>>b;
        for(i=0;i<n;i++)
            cin>>a[i];
        sort();
        int min=0,count=0;
        for(i=0;i<n;i++)
        {   if(min<=b)
            {
                min=min+a[i];
                if(min<=b)
                    count++;
            }
            else
                break;
        }
        cout<<count;
        l++;
    }while(l<t);
}
 main()
{
    cin>>t;
    inpfin();

}

