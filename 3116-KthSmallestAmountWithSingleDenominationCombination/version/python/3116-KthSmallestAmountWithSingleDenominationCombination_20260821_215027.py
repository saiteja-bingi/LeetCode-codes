# Last updated: 21/8/2026, 9:50:27 pm
1class Solution:
2    def findKthSmallest(self, coins: List[int], k: int) -> int:
3        n = len(coins)
4        dic = defaultdict(list)
5        for i in range(1, n + 1):
6            for comb in itertools.combinations(coins, i):
7                dic[len(comb)].append(math.lcm(*comb))
8        
9        def count(dic, target):
10            ans = 0
11            for i in range(1, n + 1):
12                for lcm in dic[i]:
13                    ans += target // lcm * pow(-1, i + 1)
14            return ans
15        
16        start, end = min(coins), min(coins) * k
17        while start + 1 < end:
18            mid = (start + end) // 2
19            if count(dic, mid) >= k:
20                end = mid
21            else:
22                start = mid
23        if count(dic, start) >= k:
24            return start
25        else:
26            return end