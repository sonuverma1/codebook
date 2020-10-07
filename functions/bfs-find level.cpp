ll n,m,u,v;
vector<ll> adj[100005];
ll level[100005],ans=-1;
bool vis[100005];
bool is_bipartite = true;

//SHORTEST PATH IN UNWEIGHTED GRAPH
void minpath(){
    queue<ll> q;
    q.push(u);
    level[u]=0;
    vis[u]=true;
    while(!(q.empty())){
        ll cur = q.front();
        q.pop();
        for(ll i=0;i<adj[cur].size();i++){

            if(vis[adj[cur][i]] == false){

                level[adj[cur][i]] = level[cur]+1;                 
                q.push(adj[cur][i]);
                vis[adj[cur][i]] = true;
                if(adj[cur][i] == v){
                    ans = level[v];
                    return;
                } 
            }
              
        }
    }
}

void solve(){
    ll i,j,x,y;
    cin >> n >> m;
    for(i=1;i<=n;i++) {
        vis[i]=0; level[i]=-1;
    }
    for(i=0;i<m;i++){
        cin >> x >> y;
        adj[x].pb(y); adj[y].pb(x);
    }
    //find shortest path from u to v
    cin >> u >> v;
    minpath();
    cout << ans <<ln;
}

int main()
{
    fastio  
    //ll t,i=0; cin >> t; while(t--) 
        solve();
    return 0;
}
