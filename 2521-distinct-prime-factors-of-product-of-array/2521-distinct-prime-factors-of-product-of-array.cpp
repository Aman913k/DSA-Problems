class Solution {
    public:


    
    int distinctPrimeFactors(vector<int>& nums){
        vector<int> prime;
        set<int> s;
        int n=10000;

        bool check[n+1];
    memset(check, true, sizeof(check));
 
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (check[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                check[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (check[p])
         prime.push_back(p);

        
        for(auto n: nums){
            for(auto p: prime){
                if(n%p==0) s.insert(p);
            }
        }
        return s.size();
        
    }
}; 