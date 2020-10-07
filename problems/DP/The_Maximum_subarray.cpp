#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<stack>
#include<limits>
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
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<n;i++)
#define fab(i,a,b) for(i=a;i<b;i++)
ll maxSubArraySum(ll a[], ll size) 
{ 
    ll max_so_far = -10005, max_ending_here = 0; 
  
    for (ll i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 
ll maxSubsqncSum(ll a[], ll size){
    ll sum=0,max=-10004;
    for(ll i=0;i<size;i++){
        if(a[i] > 0){
            sum+=a[i];
        }
        if(a[i] > max){
            max=a[i];
        }
    }
    if(sum==0)  return max;
    else return sum;
} 
void solve() {
    ll n,i,j;
    cin >> n;
    ll a[n];
    for(i=0;i<n;i++)    cin >> a[i];
    ll sum1= maxSubArraySum(a,n);
    ll sum2= maxSubsqncSum(a,n);
    cout << sum1 << " " << sum2 << ln;
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
