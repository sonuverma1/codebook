// gives binary representation of n in string bin[] from left to right
int bin[16]={0};                // size can be changed
void decToBinary(unsigned int n) 
{ 
    vector<int> binaryNum;    //temporary binary array to be reverted
    int i = 0; 
    while (n > 0) { 
        binaryNum.pb(n%2); 
        n = n / 2;  
    } 
    ll sz = binaryNum.size();
    int j=15;
    for(int i=0;i<binaryNum.size() && j>=0;i++,j--)
    {
        bin[j]= binaryNum[i];         //reverted binary array
    }
} 
