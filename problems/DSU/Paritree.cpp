#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include <cstdio> 
#include <string> 
#include <vector> 
#include <set> 
#include <iterator> 
#include<bits/stdc++.h>
#include<queue>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//#define test ll t;cin >> t;while(t--)
#define ll long long int
#define  sll stack<ll>
#define  qll queue<ll>
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define vvll vector<vector<ll>>
#define  vpi vector<pair<int,int>>
#define maxHeap priority_queue<ll>
#define minHeap priority_queue <ll, vector<ll>, greater<ll> > 
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ppb pop_back
# define ln cout << "\n" ;
#define fabl(i,a,b) for(i=a;i<b;i++)
#define fabe(i,a,b) for(i=a;i<=b;i++)
#define fre(i,a,b) for(i=b;i>=a;i--)

ll modPow(ll x , ll pow , ll mod)
{
    ll ans=1;
    while(pow > 0)
    {
        if(pow%2 == 1)
        {
            ans = (ans*x)%mod;
        }
        x = (x*x)%mod ;
        pow = pow/2;
    }
    return ans;
}
ll n,m;

ll find(ll parent[], bool xor_uv[], ll n){
    if(parent[n]<0 || parent[n] == n){
    	parent[n] = n;
        return n;
    }
    else{
        ll root = find(parent,xor_uv,parent[n]);
        xor_uv[n] = xor_uv[n]^xor_uv[parent[n]];
        parent[n] = root;
        return root;
    }
}
void fill(ll parent[], ll n){
	for(ll i=1;i<=n;i++){
		parent[i]=i;
	}
}

void solve(){
	ll i,j,x,y;
	cin >> n >> m;
	for(i=1;i<n;i++){
		cin >> x >> y;
	}
		ll u,v;
		ll parent[n+1];
		bool xor_uv[n+1]={0};
		fill(parent,n);
		ll cnt = n-1;
		while(m--){
			cin >> u >> v >> x;
			if(cnt == -1){
                continue;
            }
            ll parent_u = find(parent,xor_uv,u);
            ll parent_v = find(parent,xor_uv,v);

            if(parent_v == parent_u){
            	if(xor_uv[u] ^ xor_uv[v] ^ x){
            		cnt=-1;
            	}
            }
            else{
            	cnt--;
                if(parent[parent_u]<parent[parent_v]){
                    parent[parent_v] = parent_u;
                    xor_uv[parent_v] = xor_uv[u]^xor_uv[v]^x;
                }
                else{
                    parent[parent_u] = parent_v;
                    xor_uv[parent_u] = xor_uv[u]^xor_uv[v]^x;
                }
            }
		}
		if(cnt==-1) {cout << "0"; ln;}
		else 
			cout << modPow(2, cnt , 1e9+7); ln;
}
int main(){
	fastio ll t; cin >> t;
	while(t--)
		solve();
    return 0;
}
