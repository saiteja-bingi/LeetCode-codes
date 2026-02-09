// Last updated: 09/02/2026, 21:05:12
class Solution {
public:
    int countMonobit(int n) {
        int count=0;
        for(int i=0;i<=n;i++){
            if(((i+1)&(i))==0) count++;
        }
        return count;
    }
};