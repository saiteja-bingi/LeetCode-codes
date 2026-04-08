// Last updated: 08/04/2026, 23:54:28
class Solution {
public:
    int mod=1e9+7;
    /*
        0<=arr[i]<=5000
        arr[i]<=arr[i+1]
        sumOfDig(arr[i])=digit[i]
        return total no of arrays

        digit[i]<=50
        max i can only keep 4999=>31

        okay lets make for 25=>997 ->3 ways
                            =>898  ->3 ways 3!/2!

        [a,b,c,d]
        ans=pos(a)*pos(b)*pos(c)....
        pos=no of possbile ways for number x for independent
        but here they are dependent

        what time complexity i have
        total=1e8/1e3=>1e5
        total digits=10
        total spaces=4(max)
        1e4<1e5
        so i cna do all arrangements

        think in terms of dp
        dp = no of ways to store digit x which is >= previous x (y)
        dp[i][j]= no of ways to build upto i where arr[i]=j,sum(j)=digitsum(i)


    */
    int getsum(int i){
        int s=0;
        while(i>0){
            s+=i%10;
            i/=10;
        }
        return s;
    }
    int countArrays(vector<int>& digitsum) {
        int n=digitsum.size();
        vector<int>group[51];
        for(int i=0;i<=5000;i++){
            int s=getsum(i);
            group[s].push_back(i);
        }
        vector<int>pre(5001,0);
        for(int pos=0;pos<n;pos++){
            vector<int>cur(5001,0);
            for(int curnum:group[digitsum[pos]]){
                if(pos==0){
                    cur[curnum]=1;
                }
                else{
                    cur[curnum]=pre[curnum];
                }
            }
            for(int num=1;num<=5000;num++) cur[num]=(cur[num-1]+cur[num])%mod;
            pre=cur;
        }
        return pre[5000];
    }
};