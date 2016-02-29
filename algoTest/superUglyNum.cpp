class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // track all the prime index
        vector<int> indexes(primes.size(),0);
        vector<int> ugly(n,INT_MAX);
        ugly[0] = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<primes.size(); j++) ugly[i] = min(ugly[i], ugly[indexes[j]]*primes[j]);
            for(int j=0; j<primes.size(); j++) indexes[j] += (ugly[i]%primes[j] == 0);
        }
        return ugly[n-1];
    }
};