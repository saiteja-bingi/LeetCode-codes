// Last updated: 15/04/2026, 00:42:30
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(),sides.end());
        int a=sides[0],b=sides[1],c=sides[2];
        if(a+b<=c) return {};
        double t1=acos((b*b+c*c-a*a)*1.0/(2*b*c));
        double t2=acos((a*a+c*c-b*b)*1.0/(2*a*c));
        double t3=acos((a*a+b*b-c*c)*1.0/(2*a*b));
        t1=t1*180.0/M_PI;
        t2=t2*180.0/M_PI;
        t3=t3*180.0/M_PI;
        vector<double>ans={t1,t2,t3};
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};