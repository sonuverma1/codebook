#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<stack>
#include<limits>
#include<math.h>
#include<vector>
#include<assert.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define  sll stack<ll>
#define  qll queue<ll>
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define test ll t;cin >>t; while(t--)
#define ln "\n"
#define fabl(i,a,b) for(i=a;i<b;i++)
#define fabe(i,a,b) for(i=a;i<=b;i++)
#define fre(i,a,b) for(i=b;i>=a;i--)
/*class first{
public:
    string str; int val;
private:
    string str2; int val2;
public:
    string get_private_string(){
        return str2;
    } 
    int mpdify_private_value(int x){
        val2=x;
    }
    int get_private_value(){
        return val2;
    }
};*/
void solve(){
    ll n,i,j,x,y,sum=0;
    cin >> n;
    string s;
    cin >> s;
    ll frq[26]={0};
    vll v;
    for(i=0;i<n;i++){
        frq[s[i]-97]++;
        v.pb(frq[s[i]-97]-1);
    }
    for(i=0;i<n;i++){
        sum+=(v[i]);
    }
    cout << sum << ln;
}
int main()
{
    fastio
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
