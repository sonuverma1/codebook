void dfs(ll nd){
    vis[nd]=1; 
    for(ll i=0;i<adj[nd].size();i++){
        if(vis[adj[nd][i]]==0) {
            dfs(adj[nd][i]);
        }
    }
}
