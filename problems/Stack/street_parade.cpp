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
	while(1)
	{
	    stack<int>st;      
	    int n,i,j,k,passed=0,flag=0;
	    cin >> n;
	    if(n==0)        break;
	    int a[n];
	    for(i=0;i<n;i+=1)
	    {
	        cin >> a[i];
	    }
	    for(i=0;i<n;i+=1)
	    {
	        if(a[i]==passed+1)
	        {  
	            passed+=1;
	            continue;
	        }
	        else if(st.empty()||(!st.empty()&&a[i]<st.top()))
	        {
	            st.push(a[i]);
	        }
	        else if(!st.empty()&&a[i]>st.top())
	        {
	           
	            if(st.top()!=passed+1)
	            {
	                flag=1;
	                break;
	            }
	            while(!st.empty()&&st.top()==passed+1)
	            {
	                st.pop();
	                passed+=1;
	            }
	            st.push(a[i]);
	        }
	    }
	    while(!st.empty())
	    {
	        if(st.top()!=passed+1)
	        {
	            flag=1;
	            while(!st.empty())
	                st.pop();
	            break;
	        }
	        else if(st.top()==passed+1)
	        {
	            st.pop();
	            passed+=1;
	        }
	    }
	    if(flag==1)     cout << "no" << "\n";
	    else            cout << "yes" << "\n";
	}
	return 0;
}
