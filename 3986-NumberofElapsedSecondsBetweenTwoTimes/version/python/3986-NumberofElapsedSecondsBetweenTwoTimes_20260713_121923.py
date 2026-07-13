# Last updated: 13/7/2026, 12:19:23 pm
1class Solution:
2    def secondsBetweenTimes(self, startTime: str, endTime: str) -> int:
3        a=list(map(int,startTime.split(":")))
4        b=list(map(int,endTime.split(":")))
5        ans=0
6        ans+=(b[0]-a[0])*3600+(b[1]-a[1])*60+b[2]-a[2]
7        return ans
8        