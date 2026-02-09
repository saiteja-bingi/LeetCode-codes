// Last updated: 09/02/2026, 21:05:47
class AuctionSystem {
public:
    unordered_map<int,set<pair<int,int>>>items;
    map<pair<int,int>,int>pos;
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        auto &s = items[itemId];
        if(pos.count({itemId,userId})){
            int am=pos[{itemId,userId}];
            pos.erase({itemId,userId});
            s.erase({am,userId});
        }
        items[itemId].insert({bidAmount,userId});
        pos[{itemId,userId}]=bidAmount;
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        removeBid(userId,itemId);
        addBid(userId,itemId,newAmount);
    }
    
    void removeBid(int userId, int itemId) {
        auto &s = items[itemId];
        if(pos.count({itemId,userId})){
            int am=pos[{itemId,userId}];
            pos.erase({itemId,userId});
            s.erase({am,userId});
        }
    }
    
    int getHighestBidder(int itemId) {
        auto &s = items[itemId];
        if(s.empty()) return -1;
        auto it=prev(s.end());
        return it->second;

    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */