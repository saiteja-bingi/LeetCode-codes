# Last updated: 19/8/2026, 11:57:54 pm
class Solution:
    def secondsBetweenTimes(self, startTime: str, endTime: str) -> int:
        a=list(map(int,startTime.split(":")))
        b=list(map(int,endTime.split(":")))
        ans=0
        ans+=(b[0]-a[0])*3600+(b[1]-a[1])*60+b[2]-a[2]
        return ans
        