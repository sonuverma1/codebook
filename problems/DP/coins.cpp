#include <iostream>
#include<iomanip>
#include<cmath>
#include<bits/stdc++.h>
#include<stack>
#include<string>
#include<map>
#include<iterator>
using namespace std; 
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll rec(ll n)
{
	if(n<12)
	return n;
	else{
		return rec(n/2)+rec(n/3)+rec(n/4);
	}
}
int main()
{
	fastio
	ll n;
	while(cin >> n)
	{
		ll k=rec(n);
		cout << k <<"\n";
	}
	return 0;
} 
