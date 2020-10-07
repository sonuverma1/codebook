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
