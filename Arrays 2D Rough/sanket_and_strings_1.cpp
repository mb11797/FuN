#include <iostream>
#include<string.h>

using namespace std;

int main()
{
  int k;
  cin>>k;

   string str;

   cin>>str;
   int i;

   int l=str.length();

    int c1=0,c2=0;

   for(i=0;i<l;i++)
   {
     if(str[i]=='a')
        c1++;
     else if(str[i]=='b')
        c2++;
   }

  // int m;

  int t;

    if(c1>c2)
    {
      if(k<=c2)
      t=c1+k;

      else
        if(k>c2)
        t=c1+c2;
    }

    else if(c2>c1)
    {
        if(k<=c1)
            t=c2+k;

        else if(k>c1)
            t=c1+c2;
    }

    else if(c1==c2)
    {
        if(k<=c1)
         t=c1+k;
        else if(k>c1)
         t=c1+c2;
    }

   cout<<t;


    return 0;
}
