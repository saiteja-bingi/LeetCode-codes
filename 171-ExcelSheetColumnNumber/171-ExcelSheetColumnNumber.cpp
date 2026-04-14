// Last updated: 15/04/2026, 00:47:01
class Solution {
public:
    int titleToNumber(string col) {
        int n=col.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum*26+(col[i]-64);
        }
        // sum+=(col[n-1]-64);
        return sum;
    }
};