#include<iostream>
using namespace std;
int a[10000][10000],k[100],r[100],c[100],n,t,count=0;
void check()
{
    int i,j,l,u=0,v=0,e=0,p,f,q;

    do
    {
        count++;
        cin>>n;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            cin>>l;
            if(l<=n)
                a[i][j]=l;
            else
                 a[i][j]=0;
            if(i==j)
                u=a[i][j]+u;
        }
        for(i=0;i<n;i++)
        {   f=0;
            for(p=0;p<n;p++)
            {
            for(j=p+1;j<n;j++)
        {
            if(a[i][p]==a[i][j])
            {
                v++;
                f=1;
                break;
            }
        }
        if(f=1)
            break;
            }
        }
        for(i=0;i<n;i++)
        {   q=0;
            for(p=0;p<n;p++)
            {
            for(j=p+1;j<n;j++)
        {
            if(a[p][i]==a[j][i])
            {
                e++;
                q=1;
                break;
            }
        }
        if(q==1)
            break;
            }
        }
        r[count]=v;
        c[count]=e;
        k[count]=u;
    }while(count<t);
}
void display()
{
    int i;
    for(i=0;i<t;i++)
        cout<<"Case #"<<i+1<<":"<<" "<<k[i+1]<<"\t"<<r[i+1]<<"\t"<<c[i+1]<<"\n";
}
 main()
{
    cin>>t;
    check();
    display();
}
