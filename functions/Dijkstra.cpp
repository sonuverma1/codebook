#define infinite 100000000000000010

//Dijkstra using set :- directed graph , non negative edge weights

ll n,m,u,v;
vector<pair<ll,ll>> adj[100005];
ll par[100005];
bool vis[100005];
vector<ll> dist(100005,infinite);

void Dijkstra(ll src){
    dist[src] = 0;
    ll u;
    set<pair<ll,ll> > s;
    s.insert({dist[src], src});
    while(!s.empty()){
        u = s.begin() -> second;
        s.erase(s.begin());
        for(auto p : adj[u]) //adj[v][i] = pair(vertex, weight)
            if(dist[p.first] > dist[u] + p.second){
                s.erase({dist[p.first], p.first});
            dist[p.first] = dist[u] + p.second;
            s.insert({dist[p.first], p.first});
            }
    }
}
void solve(){
    ll i,j,x,y,cost;
    cin >> n >> m;
    for(i=1;i<=n;i++) {
        vis[i]=0; 
    }
    for(i=0;i<m;i++){
        cin >> x >> y >> cost;
        adj[x].pb(make_pair(y,cost)); //adj[y].pb(make_pair(x,cost));
    }
    cin >> u >> v;
    Dijkstra(u);
    if(dist[v] != infinite)
        cout << dist[v] << ln;
    else cout << "-1\n";
}


int main()
{
    fastio  
        solve();
    return 0;
}
