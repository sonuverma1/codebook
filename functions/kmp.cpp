#include<bits/stdc++.h>
#include <cmath> 
#include <iomanip> 
#include <iostream> 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int 
using namespace std;
//kmp
void computelps(char*pat , ll m, ll*lps)
{
	ll len=0,i=1;
	lps[0]=0;
	while(i<m)
	{
		if(lps[i]==lps[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}
void kmp(char* pat, ll m, char* txt, ll n)
{
	ll i=0,j=0;
	ll lps[m]={0};
	ll len =0;
	computelps(pat, m, lps);
	i=0,j=0;
	while(i<n)
	{
		if(txt[i]== pat[j])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			j=0;
			cout << "pattern found at: " << i-m << "\n";
		}
		else if(j<m && txt[i] != pat[j])
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				i=i+1;
			}
		}
	}
}
int main() {
	fastio
	char *s1="abcabcabcabcabc";
	char* s2= "abc";
	ll n=strlen(s1), m=strlen(s2);
	//cout << m << " " << n;
	kmp(s2, m , s1, n);
	return 0;
}