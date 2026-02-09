// Last updated: 09/02/2026, 21:05:32
#define ll long long
#define vll vector<long long>
#define vvl vector<vll>

#define pb push_back
#define all(x) x.begin(), x.end()

#define mapii map<int,int>
#define mapll map<long long,long long>
#define mapci map<char,int>
#define unmap unordered_map<int,int>
#define unmapll unordered_map<ll,ll>

#define pii pair<int,int>
#define pll pair<long long,long long>

#define str string

#define fi first
#define se second

// ------------------- Loop Macros -------------------
#define ffor(i,a,b) for(int i=(a);i<(b);i++)
#define forr(i,a,b) for(int i=(a);i>(b);i--)


class Solution {
public:
    int finalElement(vector<int>& arr) {
        ll n=arr.size();
        return max(arr[0],arr[n-1]);
    }
};





