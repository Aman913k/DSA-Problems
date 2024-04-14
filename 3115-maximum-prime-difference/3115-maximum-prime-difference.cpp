void Sieve(map<int, int> & mp) {  
    bool prime[101];
    memset(prime, true, sizeof(prime));
  
    for (int p = 2; p * p <= 101; p++) {
        if (prime[p] == true) { 
            for (int i = p * p; i <= 101; i += p)
                prime[i] = false;
        }
    }
  
    // Print all prime numbers
    for (int p = 2; p <= 100; p++)
        if (prime[p])
            mp[p]++; 
}



class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        Sieve(mp);
        
        int i=0, j=n-1;
        
        for(i=0; i<n; i++){
            if(mp[nums[i]]) break;
        }
        
        for(j=n-1; j>=0; j--){
            if(mp[nums[j]]) break;
        }
        
        return j-i;
    }
};