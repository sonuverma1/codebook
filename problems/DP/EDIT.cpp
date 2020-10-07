#include <iostream>
#include<bits/stdc++.h>
#include<string>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main() 
{
	fastio
	string s;
	while(cin >> s)
    {
	    long int n,i,j,oddcap=0,odds=0,evencap=0,evens=0,ans=0;
	    n=s.size();
	    //cout << n << "  ";
	    for(i=0;i<n;i++)
	    {
	        if(i&1)
	        {
	            if(s[i]>='a'&&s[i]<='z')
	                evens+=1;
	            else
	                evencap+=1;
	        }
	        else
	        {
	            if(s[i]>='a'&&s[i]<='z')
	                odds+=1;
	            else
	                oddcap+=1;
	        }
	    }
	    ans=min(oddcap+evens,odds+evencap);
	    cout << ans << "\n";
	    
	}
	return 0;
}
