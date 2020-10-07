void heapify(int arr[], int n, int i) 
{ 
    int smallest = i;
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
    if (l < n && arr[l] < arr[smallest]) 
        smallest = l; 
    if (r < n && arr[r] < arr[smallest]) 
        smallest = r; 
    if (smallest != i) { 
        swap(arr[i], arr[smallest]); 
        heapify(arr, n, smallest); 
    } 
} 
void buildHeap(int arr[], int n) 
{ 
    int startIdx = (n / 2) - 1; 
    for (int i = startIdx; i >= 0; i--) { 
        heapify(arr, n, i); 
    } 
} 
