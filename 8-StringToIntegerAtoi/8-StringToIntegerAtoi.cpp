// Last updated: 10/27/2025, 7:10:35 PM
class Solution {
public:
    unordered_map<int,int>mp={
    {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1},
    {5, 1}, {6, 1}, {7, 1}, {8, 1}, {9, 1}
};
    long long number(string &s,int i,long long num){
        if(s[i]=='\0'||mp.find(s[i]-'0')==mp.end()){
            return num;
        }
        int digit=s[i]-'0';
        if (num > (LLONG_MAX - digit) / 10) {
            return LLONG_MAX;
        }

        return number(s,i+1,num*10+digit);
    }
    int myAtoi(string s) {
        int i=0,sign=1;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }
        while((s[i]-'0')==0){
            i++;
        }
        long long num=number(s,i,0);
        num= sign*num;
        if (num < INT_MIN) return INT_MIN;
        if (num > INT_MAX) return INT_MAX;
        return num;
    }
};