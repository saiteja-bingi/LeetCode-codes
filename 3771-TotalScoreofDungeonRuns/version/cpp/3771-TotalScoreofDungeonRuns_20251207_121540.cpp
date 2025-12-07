// Last updated: 12/7/2025, 12:15:40 PM
1class Solution {
2public:
3    int largestPrime(int n) {
4        vector<bool> isPrime(n + 1, true);
5        isPrime[0] = isPrime[1] = false;
6
7        for(int i = 2; i * i <= n; i++){
8            if(isPrime[i]){
9                for(int j = i * i; j <= n; j += i){
10                    isPrime[j] = false;
11                }
12            }
13        }
14
15        vector<int> primes;
16        for(int i = 2; i <= n; i++){
17            if(isPrime[i]) primes.push_back(i);
18        }
19        int ans=0;
20        int m=primes.size();
21        long long sum=0;
22        for(int i=0;i<m;i++){
23            sum+=primes[i];
24            if(sum>n) break;
25            if(isPrime[sum]) ans=sum;
26        }
27
28        return ans;
29    }
30};