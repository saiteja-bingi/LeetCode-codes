// Last updated: 15/04/2026, 00:45:30
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int bts=log2(n)+1;
        int ps=(1<<bts);
        cout<<ps<<endl;
        ps--;
        return ps^n; 
    }
};