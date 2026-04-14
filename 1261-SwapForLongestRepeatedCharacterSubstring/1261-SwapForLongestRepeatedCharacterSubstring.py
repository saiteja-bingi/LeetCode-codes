# Last updated: 15/04/2026, 00:45:28
class Solution:
    def maxRepOpt1(self, s: str) -> int:
        s+=" "
        n=len(s)
        mp={}
        freq={}
        idx=0
        for i in range(0,n-1):
            if s[i] not in mp:
                mp[s[i]]=[]
                freq[s[i]]=0
            if s[i]!=s[i+1]:
                mp[s[i]].append([idx,i])
                idx=i+1
            freq[s[i]]+=1
        # print(mp)

        ans=0
        for key,val in mp.items():
            m=len(val)
            for i in range(m-1):
                if(val[i][1]==val[i+1][0]-2):
                    a1=val[i][1]-val[i][0]+1
                    a2=val[i+1][1]-val[i+1][0]+1
                    if(freq[key]-a1-a2>0):
                        ans=max(ans,a1+a2+1)
                    else:
                        ans=max(ans,a1+a2)
                else:
                    a1=val[i][1]-val[i][0]+1
                    if(freq[key]-a1>0):
                        ans=max(ans,a1+1)
                    else:
                        ans=max(ans,a1)
            a=val[m-1][1]-val[m-1][0]+1
            if(freq[key]-a>0):
                ans=max(ans,a+1)
            else:
                ans=max(ans,a)
        return ans


        