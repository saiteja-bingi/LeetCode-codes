// Last updated: 15/8/2026, 8:41:59 am
1class MyCalendar {
2public:
3    MyCalendar() {
4        
5    }
6    map<int,int>mp;
7    bool book(int startTime, int endTime) {
8        auto it=mp.lower_bound(startTime);
9        if(it!=mp.end()&&it->first<endTime) return false;
10        if(it!=mp.begin()){
11            auto pr=prev(it);
12            if(pr->second>startTime) return false;
13        }
14        mp[startTime]=endTime;
15        return true;
16    }
17};
18
19/**
20 * Your MyCalendar object will be instantiated and called as such:
21 * MyCalendar* obj = new MyCalendar();
22 * bool param_1 = obj->book(startTime,endTime);
23 */