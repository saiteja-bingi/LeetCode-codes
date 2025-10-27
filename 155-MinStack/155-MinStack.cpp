// Last updated: 10/27/2025, 7:08:56 PM
class MinStack {
    stack<long long>st;
    long long minele;
public:
    MinStack() {
        minele=INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minele=val;
        }
        else{
            if(val>=minele) st.push(val);
            else{
                st.push(2LL*val-minele);
                minele=val;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top()>=minele) st.pop();
        else{
            minele=2*minele-st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.top()>minele){
            return st.top();
        }
        else{
            return minele;
        }
    }
    
    int getMin() {
        return minele;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */