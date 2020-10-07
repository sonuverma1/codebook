
ll n,m;
bool ans = true, has_bridge=false;
vll adj[100005];
ll vis[100005], in[100005], low[100005], timer;
vpll directed_edges;

void dfs(ll nd, ll par){
    vis[nd]=1;
    in[nd] = low[nd] = timer++;
    for(ll i=0;i<adj[nd].size();i++){
        if(adj[nd][i] == par){
            continue;
        }
        if(vis[adj[nd][i]] ==true){
            low[nd] = min(low[nd], in[adj[nd][i]]);
            
            //back edge - orient directed_edge from child to parent
            if(in[nd] > in[adj[nd][i]]){
                directed_edges.pb({nd, adj[nd][i]});
            }
        }
        else if(vis[adj[nd][i]] ==false){
            dfs(adj[nd][i], nd);
            if(low[adj[nd][i]] > in[nd]){
                has_bridge=true;
                return;
            }
             
            //node->child -forward edge 
            //-directed edge me insert karo edge from nd to its child
            directed_edges.pb({nd, adj[nd][i]});
            low[nd] = min(low[nd], low[adj[nd][i]]);
            
        }
    }
}

void solve(){
    cin >> n >> m;
    ll i,j,x,y;
    memset(vis,0,sizeof(vis));
    timer =0; has_bridge=false;
    directed_edges.clear();
    for(i=0;i<m;i++){
        cin >> x >> y;
        adj[x].pb(y); adj[y].pb(x);
    }
    dfs(1, -1);
    if(has_bridge){
        cout << "0"; ln ; return;
    }
    for(i=0;i<directed_edges.size();i++){
        cout << directed_edges[i].ff << " " << directed_edges[i].ss; ln;
    }
}
