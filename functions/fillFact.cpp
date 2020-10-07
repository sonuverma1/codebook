ll fact[1000006];
void fillFact()
{
    ll i;
    fact[0]=1;
    for(i=1;i<1000006;i++)
    {
        fact[i]= (fact[i-1]*i)% mod;
    }
}
