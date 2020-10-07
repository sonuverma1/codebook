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

using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define  sll stack<ll>
#define  qll queue<ll>
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define  vpi vector<pair<int,int>>
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

ll n;
ll level[35][35];
bool vis[35][35];
char grid[35][35];
pair<ll,ll> start, endpnt;

ll dx[] = {-1,0,1,0};
ll dy[] = {0,-1,0,1};

bool isValid(ll x, ll y){
    if(x<0 || x>n-1 || y<0 || y>n-1){
        return false;
    }
    if(grid[x][y] == 'T'){
        return false;
    }
    if(vis[x][y] == true){
        return false;
    }
    return true;
}

void bfs(){
    queue<pair<ll,ll>> q;
    q.push(start);
    level[start.ff][start.ss]=0;
    vis[start.ff][start.ss]=true;
    while(!(q.empty())){
        pair<ll,ll> cur = q.front();
        vis[cur.ff][cur.ss]=true;
        if(cur.ff == endpnt.ff && cur.ss == endpnt.ss){
            return;
        }
        q.pop();
        for(int i=0;i<4;i++){
            if(isValid(cur.ff+dx[i], cur.ss+dy[i])){
                level[cur.ff + dx[i]][cur.ss + dy[i]] = level[cur.ff][cur.ss] +1;
                q.push({cur.ff+dx[i], cur.ss+dy[i]});
            }
        }
    }
}
void solve(){
    ll i,j,x,y;
    cin >> n;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            vis[i][j]=0; level[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'S'){
                start = {i,j};
            }
            if(grid[i][j] == 'E'){
                endpnt = {i,j};
            }
        }
    }
    bfs();
    if(vis[endpnt.ff][endpnt.ss]){
        cout << level[endpnt.ff][endpnt.ss]; ln;
    }
    else{
        cout << "-1\n";
    }
}

int main() 
{
	fastio
	//ll t; cin >> t; while(t--)
        solve();
	return 0;
}
