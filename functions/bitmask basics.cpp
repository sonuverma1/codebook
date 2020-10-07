ll setbit(ll b , ll i){
	b = b|(1<<i);
	return b;
}
ll unsetbit(ll b , ll i){
	b = b&(!(1<<i));
	return b;
}
bool check(ll b , ll i){
	if(b&(1<<i))
		return 1;
	else return 0;
}
