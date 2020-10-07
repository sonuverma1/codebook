#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include<map>
#include<queue>
#include <sstream>      //contains 'istringstream'
#include<algorithm>
#include <assert.h> 
# include <cstdio> 
# include <string> 
# include <vector>
#include<stdlib.h>
#include<set> 
#include<list>
#include<math.h>
#include<iomanip>
#include <string.h> 
using namespace std;
#define ln cout << "\n";
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll unsigned long long int
#define  sll stack<ll>
#define  qll queue<ll>
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define  vpll vector<pair<ll,ll>>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define test ll t; cin >> t; while(t--)
#define log log2
#define cases cout << "Case " << i << ":\n"; 
#define tests ll t,i; cin >> t; for(i=1;i<=t;i++)

void solve(){
    ll n,i,j,x,y,k,l;
    cin >> n >> k;
    string s;
    cin >> s;
    string temp;
    ll upto =0;
    for(i=0;i<n;i++){
        temp.pb('0');
    }
    if(s==temp){
        cout << "0\n"; return;
    }
    temp.clear();
    for(i=0;i<n;i++){
        temp.pb('1');
    }
    if(s==temp){
        cout << "0\n"; return;
    }
    if(k==0){
        ll cnt=0;
        for(i=0;i<n;i++){
            if(s[i]=='0'){
                cnt++;
            }
        }
        cout << cnt; ln ; return;
    }
    vll vmid, vside;
    //if(s[0]!='1'){
        for(i=0;i<n;i++){
            if(s[i]=='1'){
                vside.pb(i); break;
            }
        }
    //}
    //if(s[n-1] != '1'){
        for(i=n-1;i>0;i--){
            if(s[i]=='1'){
                upto =i;
                vside.pb(n-1-i); break;
            }
        }
    //}
    i=vside[0]; 
    for(;i<upto;i++){
        if(s[i]=='1'){
            continue;
        }
        else{
            ll start=i, end;
            ll cntr=1; i++;
            while(s[i] =='0'){
                cntr++; i++;
            }
            end =i;
            i--;
            //vmid.pb(end-start);
            vmid.pb(cntr);
        }
    }
    sort(vmid.begin(), vmid.end(), greater<ll>());
    sort(vside.begin(), vside.end(), greater<ll>());
    if(k&1){
        vside.erase(vside.begin());
        k--;
    }
    i=0;
    ll sz = vmid.size();
    while(k>2 && i<sz-1){
        i++;
        k-=2;
    }
    if(k>=2){
        if(vmid[i] > vside[0]){
            i++; k-=2;
        }
        if(k>0 && vside.size()>0){
            vside.erase(vside.begin()); k-=1;
            if(vside.size()>0){
                vside.erase(vside.begin()); k-=1;
            }
        }
    }
    if(k>=2){
        if(i<sz && vside.size()>0 && vmid[i] > vside[0]){
            i++; k-=2;
        }
        else if(i<sz){
            i++; k-=2;
        }
        if(k>0 && vside.size()>0){
            vside.erase(vside.begin()); k-=1;
            if(k>0 && vside.size()>0){
                vside.erase(vside.begin()); k-=1;
            }
        }
    }
    ll sum=0;
    for(;i<sz;i++){
        sum+=vmid[i];
    }
    for(i=0;i<vside.size();i++){
        sum+=vside[i];
    }
    cout << sum ; ln;
}

int main()
{
    fastio  

    tests{
        //cases
        solve();
    }
    return 0;
}
