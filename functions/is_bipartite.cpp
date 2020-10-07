#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include <assert.h> 
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define  sll stack<ll>
#define  qll queue<ll>
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define  vpi vector<pair<int,int>>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define ln "\n"
#define fab(i,a,b) for(i=a;i<b;i++)
#define fabe(i,a,b) for(i=a;i<=b;i++)
#define fre(i,a,b) for(i=b;i>=a;i--)
# include <cstdio> 
# include <string> 
# include <vector> 
#include<math.h>

ll n,m,u,v;
vector<ll> adj[100005];
ll clr[100005];
bool vis[100005];
bool is_bipartite = true;

void bfs(ll start){
    queue<ll> q;
    q.push(start);
    while(!(q.empty())){
        ll cur = q.front();
        q.pop();
        for(ll i=0;i<adj[cur].size();i++){
            if(clr[cur]==0 && clr[adj[cur][i]] == -1){
                clr[adj[cur][i]] = 1;
                q.push(adj[cur][i]);
            }
            else if(clr[cur]==1 && clr[adj[cur][i]] == -1){
                clr[adj[cur][i]] = 0;
                q.push(adj[cur][i]);
            }
            else if(clr[i] != -1 && clr[adj[cur][i]]==clr[cur]){
                is_bipartite = false; return;
            }
        }
    }
}

void solve(){
    ll i,j,x,y;
    cin >> n >> m;
    for(i=1;i<=n;i++) {
        vis[i]=0; clr[i]=-1;
    }
    for(i=0;i<m;i++){
        cin >> x >> y;
        adj[x].pb(y); adj[y].pb(x);
    }
    clr[1]=1;
    bfs(1);
    cout << (is_bipartite? "1":"0") << ln;
}

int main()
{
    fastio  
    //ll t,i=0; cin >> t; while(t--) 
        solve();
    return 0;
}
