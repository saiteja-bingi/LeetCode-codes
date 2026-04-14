// Last updated: 15/04/2026, 00:44:15
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        =>i need to divide the fgird into two sections either horizontal or vertical
        such taht sums are same
        
        =>and if not i can remove atmost one element
            only if the remaining section are connected
        
        =>i need to think of n or nlogn solutions

        when a cell is makes the section diconnecting

        so i came to know about the disconenction it happens only 
        when thre is only one row or one column

    */

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m =grid[0].size();

        long long tsum=0;
        unordered_map<long long,int> total;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                tsum+=grid[i][j];
                total[grid[i][j]]++;
            }
        }

        unordered_map<long long,int> top;
        long long sum=0;

        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
                top[grid[i][j]]++;
                total[grid[i][j]]--;
                if(total[grid[i][j]]==0) total.erase(grid[i][j]);
            }

            long long rem = tsum - sum;
            if(sum == rem) return true;

            long long diff = (sum > rem) ? (sum - rem) : (rem - sum);

            if(sum > rem){
                if(i==0 || m==1){
                    long long tl = grid[0][0];
                    long long tr = (m==1) ? grid[i][0] : grid[0][m-1];
                    if(tl==diff || tr==diff) return true;
                }else{
                    if(top.count(diff)) return true;
                }
            }else{
                if(i==n-2 || m==1){
                    long long bl = grid[n-1][0];
                    long long br = (m==1) ? grid[i+1][0] : grid[n-1][m-1];
                    if(bl==diff || br==diff) return true;
                }else{
                    if(total.count(diff)) return true;
                }
            }
        }

        total.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total[grid[i][j]]++;
            }
        }

        unordered_map<long long,int> left;
        sum=0;

        for(int j=0;j<m-1;j++){
            for(int i=0;i<n;i++){
                sum+=grid[i][j];
                left[grid[i][j]]++;
                total[grid[i][j]]--;
                if(total[grid[i][j]]==0) total.erase(grid[i][j]);
            }

            long long rem = tsum - sum;
            if(sum == rem) return true;

            long long diff = (sum > rem) ? (sum - rem) : (rem - sum);

            if(sum > rem){
                if(j==0 || n==1){
                    long long tl = grid[0][0];
                    long long bl = (n==1) ? grid[0][j] : grid[n-1][0];
                    if(tl==diff || bl==diff) return true;
                }else{
                    if(left.count(diff)) return true;
                }
            }else{
                if(j==m-2 || n==1){
                    long long tr = grid[0][m-1];
                    long long br = (n==1) ? grid[0][j+1] : grid[n-1][m-1];
                    if(tr==diff || br==diff) return true;
                }else{
                    if(total.count(diff)) return true;
                }
            }
        }

        return false;
    }
};