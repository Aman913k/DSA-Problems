class Solution {
public:
    int countPrimes(int n) {
        bool prime[n+1];
        memset(prime, true, sizeof(prime));
        
        for(int p=2; p*p<=n; p++){
            if(prime[p]==true){
                for(int i=p*p; i<=n; i+=p)
                    prime[i]=false;
            }  
        }
        
        vector<int> primes;
        for(int i=2; i<=n; i++) if(prime[i] && i!=n) primes.push_back(i);
        
        
        return primes.size();
    }
};