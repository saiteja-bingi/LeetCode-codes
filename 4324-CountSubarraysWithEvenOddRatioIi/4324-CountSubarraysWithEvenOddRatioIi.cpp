// Last updated: 19/8/2026, 11:58:24 pm
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;


class Solution {
public:
    /*
        x*b+y*(-a)<=0
        if even +b else -a
        find sub sum<=0
        pre[r]-pre[l-1]<=0
        p(l-1)>=p(r)
        for any r find how many prev prefx >=p(r)
        order key=m ele <p(r)

    */
    typedef tree<
        long long,
        null_type,
        less_equal<long long>,
        rb_tree_tag,
        tree_order_statistics_node_update
    > ordered_set;

    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        long long ans=0;
        long long pre=0;
        ordered_set st;
        st.insert(0);
        for(int i=0;i<n;i++){
            pre+=((nums[i]&1)?-a:b);
            long long k=st.order_of_key(pre);
            ans+=st.size()-k;
            st.insert(pre);
        }
        return ans;
    }
};