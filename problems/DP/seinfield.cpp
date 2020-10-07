#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int llu;
 
int main() 
{
    llu n=0;
    while(1)
    {   n++;
        int c1=0,c2=0,c=0;
        string s;
        getline(cin,s);
        if(s[0]=='-')       break;
        int l=s.size();
        for(int i=0;i<l;i++)
        {
            if(s[i]=='{')
            c1++;
            else if(c1!=0&&s[i]=='}')
            c1--;
            else if(c1==0&&s[i]=='}')
            c2++;
        }
        if(c2==0)   c=c1/2;
        else if(c1==0)  c=c2/2;
        else if((c1&1)&&(c2&1))     c=(c1+c2)/2+1;
        else if(!(c1&1)&&!(c2&1))   c=(c1+c2)/2;
        printf("%llu. %d\n",n,c);
    }
	return 0;
}
 
