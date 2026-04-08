// Last updated: 08/04/2026, 23:54:29
class EventManager {
public:
    
    // small event id with max priority
    struct cmp{
        bool operator()(pair<int,int>a,pair<int,int>b){
            if(a.first==b.first) return a.second>b.second;
            return a.first<b.first;
        }
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>,cmp> pq;
    map<int,int>mp;
    EventManager(vector<vector<int>>& events) {
        for(auto it:events){
            pq.push({it[1],it[0]});
            mp[it[0]]=it[1];
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId]=newPriority;
        pq.push({newPriority,eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto [p,id]=pq.top();
            if(!mp.count(id)){
                pq.pop();
                continue;
            }
            if(mp[id]!=p){
                pq.pop();
                continue;
            }
            else{
                pq.pop();
                mp.erase(id);
                return id;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */