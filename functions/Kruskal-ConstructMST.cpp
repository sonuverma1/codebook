#include<iomanip>
//MST - KRUSKAL TO FIND MST OF GIVEN GRAPH(GRAPH GIVEN IN FORM OF POINTS IN 2D PLANE)
struct edge{
    pair<ll,ll> a,b;
    double cost;
};

bool cmp(edge e1 , edge e2){
    return e1.cost <= e2.cost;
}

ll n,m;
vpll pnts; map<pair<ll,ll>,pair<ll,ll>> parent;
vector<pair<pair<ll,ll>,pair<ll,ll>>> result_edges;
vector<edge> e;

map<pair<ll,ll>,ll> sz;

pair<ll,ll> root(pair<ll,ll> i){
    while(parent[i]!=i){
        i=parent[i];
    }
    return i;
}

bool find(pair<ll,ll> a,pair<ll,ll> b) {
    pair<ll,ll> roota=root(a);
    pair<ll,ll> rootb=root(b);
    if(roota == rootb)
        return 1;
    else
        return 0;
}
void unn(pair<ll,ll> a, pair<ll,ll> b) {
    pair<ll,ll> roota=root(a);
    pair<ll,ll> rootb=root(b);
    if(roota==rootb)
        return ;
    else{
        if(sz[roota]<sz[rootb]){
            parent[roota]=parent[rootb];
            sz[rootb]+=sz[roota];
            sz[roota]=0;
        }
        else{
            parent[rootb]=parent[roota];
            sz[roota]+=sz[rootb];
            sz[rootb]=0;
        }
    }
}
void preDSU(){
    for(ll i=0;i<n;i++){
        parent[pnts[i]] = pnts[i];
        sz[pnts[i]]=0;
    }
}

bool cycle(edge edg){
    if(find(edg.a,edg.b))
        return true;
    else return false;
}

double Kruskal(){
    ll i,sz,cnt=0;
    double ans;
    sz = e.size();
    for(i=0;i<sz;i++){
        if(cnt == n-1) break;
        if(cycle(e[i]))
            continue;
        else{
            unn(e[i].a,e[i].b);
            result_edges.pb({e[i].a,e[i].b});
            ans += e[i].cost;
            cnt++;
        }
    }
    return ans;
}

void solve(){
    ll i,j,x,y;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> x >> y;
        pnts.pb({x,y});
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            ll x1,x2,y1,y2;
            x1 = pnts[i].f; y1 = pnts[i].s;
            x2 = pnts[j].f; y2 = pnts[j].s;
            double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
            edge k;
            k.a.f = x1 , k.a.s = y1;
            k.b.f = x2 , k.b.s = y2;
            k.cost = d;
            e.pb(k);
        }
    }
    sort(e.begin(),e.end(),cmp);
    preDSU();
    //double sum_of_wt_mst = Kruskal();
    cout << fixed << setprecision(9) << Kruskal();
}


int main()
{
    fastio  
    //ll t,i=0; cin >> t; while(t--) 
        solve();
    return 0;
}
