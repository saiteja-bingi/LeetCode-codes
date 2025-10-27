// Last updated: 10/27/2025, 7:05:54 PM
class Solution {
public:
    vector<int> evenOddBit(int n) {
        unsigned int move=1;
        int even=0,odd=0;
        for(int i=0;i<32;i++){
            if(n&move){
                if(i%2==0) even++;
                else odd++;
            }
            move=move<<1;
        }
        return {even,odd};
    }
};