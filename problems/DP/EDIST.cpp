#include <iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
 
long int d[2104][2104];
string a,b;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    unsigned long long int t;
    cin >>t;
    while(t--)
    {
    	
    	long int l1,l2,i,j;
    	//scanf("%s",a);
    	//scanf("%s",b);
    	cin >> a;
    	cin >> b;
    	//l1=strlen(a);
    	//l2=strlen(b);
    	l1=a.size();
    	l2=b.size();
    	d[0][0]=0;
    	for(i=0;i<l1+1;i++)
    		d[i][0]=i;
    	for(j=0;j<l2+1;j++)
    		d[0][j]=j;
    	for(j=1;j<l2+1;j++)
    	{
    		for(i=1;i<l1+1;i++)
    		{
    			long int x,y,z,w;
    			x=d[i][j-1]+1;
    			y=d[i-1][j]+1;
    			z=d[i-1][j-1];
    			w=d[i-1][j-1]+1;
    			long int k=min(x,y);
    			if(a[i-1]==b[j-1])
    			{
    				
    				d[i][j]=min(k,z);
    			}
    			else
    			{
    				//long int k=min(x,y);
    				d[i][j]=min(k,w);
    			}
    		}
    	}
    	/*for(i=0;i<l1+1;i++)
    	{
    		for(j=0;j<l2+1;j++)
    			cout <<d[i][j]<< " ";
    		cout << "\n";
    	}*/
    	cout << d[l1][l2] << endl;
    }
} 
