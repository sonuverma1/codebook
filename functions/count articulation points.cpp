#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include <cstring> 
#include<map>
#include<queue>
#include <utility>
#include<algorithm>
#include <assert.h>
# include <cstdio> 
# include <vector> 
#include<math.h>
#include<limits>
#include<iomanip>
#include<set>

using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define  sll stack<ll>
#define  qll queue<ll>
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define  vpll vector<pair<ll,ll>>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ppb pop_back
# define ln cout << "\n" ;
#define fab(i,a,b) for(i=a;i<b;i++)
#define fabe(i,a,b) for(i=a;i<=b;i++)
#define fre(i,a,b) for(i=b;i>=a;i--)

#define maxHeap priority_queue<ll>
#define minHeap priority_queue <ll, vector<ll>, greater<ll> > 

ll n,m;
bool ans = true, has_bridge=false;
vll adj[100005];
ll vis[100005], in[100005], low[100005], timer;
//vpll directed_edges;
set<ll> cut_vertex;

void dfs(ll nd, ll par){
    vis[nd]=1;
    in[nd] = low[nd] = timer++;
    ll chld_cnt=0;
    for(ll i=0;i<adj[nd].size();i++){
        if(adj[nd][i] == par){      //child == parent
            continue;
        }
        if(vis[adj[nd][i]] ==true){     //conencted with its ancestor-back edge
            low[nd] = min(low[nd], in[adj[nd][i]]);
        }
        else if(vis[adj[nd][i]] ==false){   //forward edge
            dfs(adj[nd][i], nd);
            chld_cnt ++;
            low[nd] = min(low[nd], low[adj[nd][i]]);
            if(in[nd] <= low[adj[nd][i]] && par !=-1){
                cut_vertex.insert(nd);
            }
        }
    }
    if(par==-1 && chld_cnt > 1){
        cut_vertex.insert(nd);
    }
}

void solve(){
    cin >> n >> m;
    if(n==0 && m==0){
        return;
    }
    ll i,j,x,y;
    memset(vis,0,sizeof(vis));
    for(i=0;i<=n;i++){
        adj[i].clear();
    }
    timer =0; has_bridge=false;
    cut_vertex.clear();
    for(i=0;i<m;i++){
        cin >> x >> y;
        adj[x].pb(y); adj[y].pb(x);
    }
    for(i=1;i<=n;i++){
        if(!(vis[i])){
            dfs(i, -1);        
        }
    }
    cout << cut_vertex.size(); ln;
}

int main() 
{
	fastio
	//ll t; cin >> t; while(t--)
	while(1){
	    solve();
	    if(n==0 && m==0){
	        break;
	    }
	}
	return 0;
}
