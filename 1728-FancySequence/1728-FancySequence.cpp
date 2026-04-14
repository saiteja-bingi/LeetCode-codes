// Last updated: 15/04/2026, 00:45:09
class Fancy {
public:

    vector<int>arr;
    map<int,pair<long long,long long>>mp;
    long long add=0,mul=1;
    long long mod=1e9+7;

    Fancy() {
        
    }
    
    void append(int val) {
        arr.push_back(val);
        mp[arr.size()-1]={mul,add};
    }
    
    void addAll(int inc) {
        add=(add+inc)%mod;
    }
    
    void multAll(int m) {
        mul=(mul*m)%mod;
        add=(add*m)%mod;
    }

    long long binpow(long long a,long long b){
        long long res=1;
        while(b>0){
            if(b&1) res=(res*a)%mod;
            a=(a*a)%mod;
            b>>=1;
        }
        return res;
    }
    
    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        long long ans=arr[idx];
        auto [smul,sadd]=mp[idx];
        long long invsmul=binpow(smul,mod-2);
        long long dmul=mul*invsmul%mod;
        long long dadd=(add-dmul*sadd%mod+mod)%mod;
        ans=(ans*dmul%mod+dadd)%mod;
        return ans;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */