#include<bits/stdc++.h>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> minSt;

    MinStack() {
        
    }
    
    void push(int x) {
        if(minSt.empty() || minSt.top() >= x)
        minSt.push(x);
        st.push(x);
    }
    
    void pop() {
        if (!minSt.empty() && !st.empty())
        {
            if (minSt.top() == st.top())
                minSt.pop();
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

int main()
{
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    if (-3 == minStack.getMin())
        cout << "PASS\n"; //   --> Returns -3.
    minStack.pop();
    if (0 == minStack.top())
        cout << "PASS\n"; //   --> Returns 0.
    if (-2 == minStack.getMin())
        cout << "PASS\n"; //   --> Returns -2.
    return 0;
}