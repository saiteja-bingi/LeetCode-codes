// Last updated: 1/11/2026, 11:10:11 AM
class Solution {
public:
    int largestPrime(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i * i <= n; i++){
            if(isPrime[i]){
                for(int j = i * i; j <= n; j += i){
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;
        for(int i = 2; i <= n; i++){
            if(isPrime[i]) primes.push_back(i);
        }
        int ans=0;
        int m=primes.size();
        long long sum=0;
        for(int i=0;i<m;i++){
            sum+=primes[i];
            if(sum>n) break;
            if(isPrime[sum]) ans=sum;
        }

        return ans;
    }
};