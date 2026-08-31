// Last updated: 31/8/2026, 8:59:30 pm
1class Solution {
2public:
3    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
4        int Min = 100000, i = 1;
5        int c[2] = {0, 0};
6
7        auto prev = head, curr = head->next, nxt = head->next->next;
8
9        auto isCrit = [&]() {
10            auto x = prev->val, y = curr->val, z = nxt->val;
11            return (x < y && y > z) || (x > y && y < z);
12        };
13
14        while (nxt) {
15            if (isCrit()) {
16                if (c[0]) Min = min(Min, i - c[c[1] > 0]);
17                c[c[0] > 0] = i;
18            }
19
20            prev = curr; curr = nxt;
21            nxt = nxt->next; i++;
22        }
23
24        if (c[1]) return {Min, c[1] - c[0]};
25
26        return {-1, -1};
27    }
28};