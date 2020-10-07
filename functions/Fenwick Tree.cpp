ll bit[1000005]={0}, n;

void update_add(ll x, ll delta)       //add "delta" at index "x"
{
    for(; x <= n; x += x&-x)
          bit[x] += delta;
}

ll query(ll x)      //returns the sum of first x elements in given array a[]
{
     ll sum = 0;
     for(; x > 0; x -= x&-x)
         sum += bit[x];
     return sum;
}
