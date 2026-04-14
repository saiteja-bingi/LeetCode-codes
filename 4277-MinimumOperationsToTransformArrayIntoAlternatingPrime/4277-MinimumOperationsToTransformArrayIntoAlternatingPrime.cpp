// Last updated: 15/04/2026, 00:42:23
#define all(x) x.begin(), x.end()
#define ll long long
class Solution {
public:
    /*
        make primes
        make non primes
    
        make non primes is easy add +1 or -1 except (2,3)
        for primes i apply binary search on prime numbers upto n
        to find < and > this non prime to make prime
    */

    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        int ele=*max_element(all(nums));
        vector<bool> isprime(ele+101,true);
        isprime[0] = isprime[1] = false;
        for (int i = 2; i <= (ele+100)/i; i++) {
            if (isprime[i]) {
                for (ll j = 1LL * i * i; j <= ele+100; j += i) {
                    isprime[j] = false;
                }
            }
        }
        vector<int>nextprime(ele+102,-1);
        int last=-1;
        for(int i=ele+100;i>=0;i--){
            if(isprime[i]) last=i;
            nextprime[i]=last;
        }

        for(int i=0;i<n;i++){
            bool isp=isprime[nums[i]];
            if(i%2==0&&isp||i%2!=0&&!isp) continue;
            if(i%2!=0){
                if(nums[i]==2) ans+=2;
                else ans+=1;
            }
            if(i%2==0){
                int np=nextprime[nums[i]];
                ans+=(np-nums[i]);
            }
        }
        return ans;
    }
};