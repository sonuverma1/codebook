#include <bits/stdc++.h>
#include <stack>
using namespace std;
const int N = 3e5 + 5;
typedef long long int ll;
ll parent[1010],sz[1010];

ll root(ll i)
{
	while(parent[i]!=i)
	{
		i=parent[i];
	}
	return i;
}

bool find(ll a,ll b)
{
	ll roota=root(a);
	ll rootb=root(b);
	if(roota == rootb)
		return 1;
	else
		return 0;
}
void unn(ll a, ll b)    //union by size
{
	ll roota=root(a);
	ll rootb=root(b);
	if(roota==rootb)
		return ;
	else{
		if(sz[roota]<sz[rootb])
		{
			parent[roota]=parent[rootb];
			sz[rootb]+=sz[roota];
			sz[roota]=0;
		}
		else
		{
			parent[rootb]=parent[roota];
			sz[roota]+=sz[rootb];
			sz[rootb]=0;
		}
	}
}

int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    return 0;
}
