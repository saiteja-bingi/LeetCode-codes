// Last updated: 2/8/2026, 10:59:48 pm
1#include <ext/pb_ds/assoc_container.hpp>
2#include <ext/pb_ds/tree_policy.hpp>
3
4using namespace __gnu_pbds;
5
6
7class Solution {
8public:
9    /*
10        x*b+y*(-a)<=0
11        if even +b else -a
12        find sub sum<=0
13        pre[r]-pre[l-1]<=0
14        p(l-1)>=p(r)
15        for any r find how many prev prefx >=p(r)
16        order key=m ele <p(r)
17
18    */
19    typedef tree<
20        long long,
21        null_type,
22        less_equal<long long>,
23        rb_tree_tag,
24        tree_order_statistics_node_update
25    > ordered_set;
26
27    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
28        int n=nums.size();
29        long long ans=0;
30        long long pre=0;
31        ordered_set st;
32        st.insert(0);
33        for(int i=0;i<n;i++){
34            pre+=((nums[i]&1)?-a:b);
35            long long k=st.order_of_key(pre);
36            ans+=st.size()-k;
37            st.insert(pre);
38        }
39        return ans;
40    }
41};