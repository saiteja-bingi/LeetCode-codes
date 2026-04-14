// Last updated: 15/04/2026, 00:45:13
class Solution {
public:
    /*
        can i do a pattern check
        if n==1 return "0"; for sure
        for s2 the length is 4-1
        s3= 8-1 2^n-1
        mid=(len+1 / 2)
        if(mid>len) i need to check in other half
        else this half
        if k==mid return 1
        else n-1,k;



        i need 7 the ele in s3 of 7 ele
        7-7+1; len-k+1;
        char =n-1,len-k+1;
        if(char==0) 1:else 0;
    
    */
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        int len=(1<<n)-1;
        int mid=(len+1)/2;
        if(mid==k) return '1';
        else if(k<mid) return findKthBit(n-1,k);

        char ch=findKthBit(n-1,len-k+1);
        if(ch=='0') return '1';
        else return '0';
    }
};