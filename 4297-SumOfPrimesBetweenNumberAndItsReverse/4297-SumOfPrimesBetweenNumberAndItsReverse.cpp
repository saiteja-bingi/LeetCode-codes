// Last updated: 19/8/2026, 11:58:54 pm
#define ll long long
class Solution {
public:
    vector<int> preprime(int n) {
        vector<bool> isprime(n + 1, true);
        vector<int> prime;
     
        isprime[0] = isprime[1] = false;
     
        for (int i = 2; i * i <= n; i++) {
            if (isprime[i]) {
                for (ll j = 1LL * i * i; j <= n; j += i) {
                    isprime[j] = false;
                }
            }
        }
     
        for (int i = 2; i <= n; i++) {
            if (isprime[i]) prime.push_back(i);
        }
     
        return prime;
    }
    int sumOfPrimesInRange(int n) {
        int m=n;
        int r=0;
        while(m>0){
            r=r*10+m%10;
            m/=10;
        }
        vector<int>primes=preprime(max(n,r));
        int sum=0;
        for(int i=0;i<primes.size();i++){
            if(primes[i]>=min(n,r)) sum+=primes[i];
        }
        return sum;
    }
};