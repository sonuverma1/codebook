ll binsch(vector<pair<ll,ll>>v , ll low, ll high , ll key) {
    while(low <= high) {
        ll mid=low + (high-low)/2;
        if(v[mid].f == key)
            return mid;
        else if(v[mid].f < key)
            low = mid+1;
        else if(v[mid].f > key)
            high = mid-1;
    }
    return -1;
}
