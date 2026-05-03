// Last updated: 3/5/2026, 8:07:25 am
1#define ll long long
2class Solution {
3public:
4    vector<int> preprime(int n) {
5        vector<bool> isprime(n + 1, true);
6        vector<int> prime;
7     
8        isprime[0] = isprime[1] = false;
9     
10        for (int i = 2; i * i <= n; i++) {
11            if (isprime[i]) {
12                for (ll j = 1LL * i * i; j <= n; j += i) {
13                    isprime[j] = false;
14                }
15            }
16        }
17     
18        for (int i = 2; i <= n; i++) {
19            if (isprime[i]) prime.push_back(i);
20        }
21     
22        return prime;
23    }
24    int sumOfPrimesInRange(int n) {
25        int m=n;
26        int r=0;
27        while(m>0){
28            r=r*10+m%10;
29            m/=10;
30        }
31        vector<int>primes=preprime(max(n,r));
32        int sum=0;
33        for(int i=0;i<primes.size();i++){
34            if(primes[i]>=min(n,r)) sum+=primes[i];
35        }
36        return sum;
37    }
38};