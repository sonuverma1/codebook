#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include <assert.h> 
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define  sll stack<ll>
#define  qll queue<ll>
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define  vpi vector<pair<int,int>>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ppb pop_back
# define ln cout << "\n" ;
#define fab(i,a,b) for(i=a;i<b;i++)
#define fabe(i,a,b) for(i=a;i<=b;i++)
#define fre(i,a,b) for(i=b;i>=a;i--)
# include <cstdio> 
# include <string> 
# include <vector> 
#include<math.h>
#include<limits>
#include<iomanip>
#define maxHeap priority_queue<ll>
#define minHeap priority_queue <ll, vector<ll>, greater<ll> > 

ll k=0;
vll v;
struct node
{
    char ch;
    ll val;
    struct node* child[26];
    bool last;
    node()
    {
        last=false;
        ll i;
        fab(i,0,26)
        {
            child[i]=NULL;
        }
    }
};

void trieconstruct(node* root,string s)
{
    ll i;
    node* temp=root;
    fab(i,0,s.length())
    {
        ll x=s[i]-'A';
        if(temp->child[x]==NULL)
        {
            node* newnode=new node();
            newnode->ch=s[i];
            newnode->val=k++;
            temp->child[x]=newnode;
        }
        temp=temp->child[x];
    }
    temp->last=true;
}

void dfs(node* root)
{
    ll i;
    for(i=0;i<26;i++)
    {
        if(root->child[i]!=NULL)
        {
            cout<<root->val<<"->"<<root->child[i]->val<<":"<<root->child[i]->ch;
            ln;
            dfs(root->child[i]);
        }
    }
}

int main()
{
    fastio;
    node* root;
    root=new node();
    root->val=k++;
    ll i,n;
    cin >> n;
    string s;
    while(n--){
        cin >> s;
        trieconstruct(root,s);
    }
    dfs(root);
    return 0;
}
