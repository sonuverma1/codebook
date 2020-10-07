//DETECT CYCLE IN GRAPH

ll n,m;
vector<ll> adj[1005];
bool white[1005],gray[1005],black[1005];
ll par[1005]={0};
bool ans=false;

bool dfs(ll nd){

    white[nd]=0; gray[nd]=1;

    for(ll i=0;i<adj[nd].size();i++){
        if(black[adj[nd][i]] == 1){
            continue;
        }
        if(gray[adj[nd][i]] == 1){
            ans=true;
            return true;
        }
        else if(white[adj[nd][i]]==1){
            par[adj[nd][i]] = nd;
            dfs(adj[nd][i]);
        }
    }
    gray[nd]=0; black[nd]=1;
    return false;
}

void cycle(){
    ll i,j,x,y;
    cin >> n >> m;
    for(i=1;i<=n;i++) {
        white[i]=gray[i]=black[i]=0; 
    }
    for(i=1;i<=n;i++) {
        white[i]=1; 
    }
    for(i=0;i<m;i++){
        cin >> x >> y;
        adj[x].pb(y); 
    }
    bool f=0;
    for(i=1;i<=n;i++){
        if(white[i] == 1)
        {
            bool k = dfs(i);
            if(k){
                //cout << 1 <<ln;
                f=1; break;
            }
        }    
    }
    if(ans==0){
        cout << 0 << ln;
    }
    else{
        cout << 1 << ln;
    }
}

int main()
{
    fastio  
    //ll t,i=0; cin >> t; while(t--) 
        cycle();
    return 0;
}
