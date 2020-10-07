// ****** 2D FENWICK TREE ****** //

long long tree[2002][2002];

void update(ll x, ll y, ll val)
{
    ll x1 = x, y1 = y;
	while(x < 2002)
	{
		y = y1;
		while(y < 2002)
		{
			tree[x][y] += val;
			y = y + (y & -y);
		}
		x = x + (x & -x);
	}
}
ll sum(ll x, ll y)
{
	ll x1 = x, y1 = y;
	ll ans = 0;
	while(x > 0)
	{
		y = y1;
		while(y > 0)
		{
			ans += tree[x][y];
			y = y - (y & -y);
		}
		x = x - (x & -x);
	}
	return ans;
}
void solve(){
    for(ll i=0;i<2002;i++){
        for(ll j=0;j<2002;j++){
            tree[i][j]=0;
        }
    }
    ll n,m,q,i,j,temp;
    cin >> n >> m >> q;
    ll total =0;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin >> temp;
            total += temp;
            update(i,j,temp);
        }
    }
    while(q--){
        char ch;
        cin >> ch;
        if(ch == '1'){
            ll x,y,val;
            cin >> x >> y >> val;		// 1 BASED INDEXING
            total += val;
            update(x,y,val);
        }
        else{
            ll x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--; y1--; 			// CONSIDERING ONE BASED INDEXING
            ll ans = sum(x2,y2) -sum(x1,y2) -sum(x2,y1) +sum(x1,y1);
            cout << ans; ln;
        }
    }
}















// ****** 3D FENWICK TREE ******** //

long long tree[105][105][105];

void update(long long x, long long y, long long z, long long val)
{
	long long x1 = x, y1 = y, z1 = z;
	while(x < 105)
	{
		y = y1;
		while(y < 105)
		{
			z = z1;
			while(z < 105)
			{
				tree[x][y][z] += val;
				z = z + (z & -z);
			}
			y = y + (y & -y);
		}
		x = x + (x & -x);
	}
}
long long sum(long long x, long long y, long long z)
{
	long long x1 = x, y1 = y, z1 = z;
	long long ans = 0;
	while(x > 0)
	{
		y = y1;
		while(y > 0)
		{
			z = z1;
			while(z > 0)
			{
				
				ans += tree[x][y][z];
				z = z - (z & -z);
			}
			y = y - (y & -y);
		}
		x = x - (x & -x);
	}
	return ans;
}
void solve(){
    ll n,q,i,j;
    cin >> n >> q;
    ll total =0;
    while(q--){
        char ch;
        cin >> ch;
        if(ch == '1'){
            ll x,y,z,val;
            cin >> x >> y >> z >> val;
            x++; y++; z++;		// ZERO BASED INDEXING FOR X,Y,Z IS USED THUS ADDED ONE BCOZ FENWICK TREE ALWAYS USE 1 BASED INDEXING
            total += val;
            update(x,y,z,val);
        }
        else{
            ll x1,y1,z1,x2,y2,z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            x2++; y2++; z2++;
            ll ans = sum(x2,y2,z2) -sum(x1,y2,z2) -sum(x2,y1,z2) -sum(x2,y2,z1) 
                     +sum(x1,y1,z2) +sum(x1,y2,z1) +sum(x2,y1,z1) -sum(x1,y1,z1);
            cout << total -ans; ln;
        }
    }
}

int main() 
{
	fastio
	//ll t; cin >> t; while(t--)
        solve();
	return 0;
}
