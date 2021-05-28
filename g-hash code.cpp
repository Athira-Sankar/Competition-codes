#include<iostream>
#include<fstream>
using namespace std;
int books[100],score[100],ll[100],shipped[100];
struct library
{
    int n;
    int signup;
    int ship;
    int b[100];
    int sss;
}l[100];
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void shipment()
{
    for(int i=0;i<100;i++)
    {
        if(l[i].sss==1)
        {
            if(l[i].n>0)
            {
                shipped[i]=shipped[i]+l[i].ship;
                l[i].n-l[i].ship;
            }
        }
    }
}
int main()
{
    ifstream f;
    ofstream out;
    int nbooks,lib,days;
    f.open("file.txt");
    out.open("output.txt");
    f>>nbooks;
    f>>lib;
    f>>days;
    cout<<nbooks<<" "<<lib<<" "<<days<<endl;
    for(int i=0;i<nbooks;i++)
    {
        f>>score[i];
        books[i]=i;
    }
    for(int i=0;i<nbooks-1;i++)
    for (int j=0;j<nbooks-i-1;j++)
        if (score[j]>score[j+1])
            {
                swap(&score[j],&score[j+1]);
                swap(&books[j],&books[j+1]);
            }
    for(int i=0;i<lib;i++)
    {
        f>>l[i].n;
        f>>l[i].signup;
        f>>l[i].ship;
        for(int j=0;j<l[i].n;j++)
            f>>l[i].b[j];
        l[i].sss=0;
    }
    int min=0;
     for(int i=0;i<lib;i++)
     {
          for(int j=0;j<lib;j++)
          {
              if(l[j].signup<l[min].signup) ////#############doubt
                min=j;
          }
          ll[i]=min;
     }
     int sign[100],count=0,a=0,b=0;;
     while(days>0)
     {
         l[ll[a]].signup--;
         days--;
         shipment();
         if(l[ll[a]].signup==0)
         {
           l[ll[a]].sss=1;
           a++;
           count++;
         }
     }
     out<<count<<"\n";

    for(int i=0;i<count;i++)
     {
          out<<ll[i];
          out<<" ";
        out<<shipped[i]/2;
        out<<"\n";
     }


   /* for(int i=0;i<nbooks;i++)
      cout<<score[i]<<" ";
      cout<<endl;
    for(int i=0;i<nbooks;i++)
      cout<<books[i]<<" ";
    */

    for(int i=0;i<a;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(l[j].sss==1)
            {
                for(int k=0;k<shipped[j]/2;k++)
                    out<<l[j].b[k]<<" ";
            }
            out<<"\n";
        }
    }
    cout<<shipped[0];
    f.close();
    out.close();
}

