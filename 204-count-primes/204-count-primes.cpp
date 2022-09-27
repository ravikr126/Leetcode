class Solution {
public:
    int countPrimes(int n) {
         // takibg all elements as prime
    vector<bool> arr(n+1, true);
    
    // for count of prime nos
    int count=0;
    
    // Starting from  2because 1 is neither prime nor composite
    for(int i=2;i<n;i++)
    {
        // if its true that is prime then make all multiples of it as true
        if(arr[i])
        {
            count++;
            
            for(int j=2*i;j<n;j+=i)
                arr[j]=false;
        }
    }
    
    return count;
    }
};