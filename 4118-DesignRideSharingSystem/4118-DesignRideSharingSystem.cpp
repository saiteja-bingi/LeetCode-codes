// Last updated: 09/02/2026, 21:05:33
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

// #define str string

#define fi first
#define se second

// ------------------- Loop Macros -------------------
#define ffor(i,a,b) for(int i=(a);i<(b);i++)
#define forr(i,a,b) for(int i=(a);i>(b);i--)



class RideSharingSystem {
public:
    queue<ll>r,d;
    map<ll,ll>mp,mp2;
    RideSharingSystem() {
        r=queue<ll>();
        d=queue<ll>();
        mp2.clear();
    }
    
    void addRider(int riderId) {
        mp2[riderId]++;
        r.push(riderId);
    }
    
    void addDriver(int driverId) {
        d.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(r.empty()||d.empty()) return {-1,-1};
        ll a=d.front();
        ll b;
        while(!mp2.count(r.front())&&!r.empty()){
            r.pop();
        }
        if(r.empty()||d.empty()) return {-1,-1};
        b=r.front();
        mp2.erase(b);
        d.pop();r.pop();
        return {(int)a,(int)b};
    }
    
    void cancelRider(int riderId) {
        if(mp2.count(riderId)){
            mp2.erase(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */