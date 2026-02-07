#include <bits/stdc++.h>
using namespace std;

class MinStack {

    // Main stack -> stores all values
    stack<int> st;

    // Helper stack -> stores minimum values
    stack<int> minSt;

public:
    MinStack() {
        // Constructor (nothing special here)
    }

    // Push element into stack
    void push(int val) {

        // Push value into main stack
        st.push(val);

        // If min stack is empty OR current value is smaller/equal
        // than current minimum -> push into min stack also
        if(minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    // Remove top element
    void pop() {

        // If top element is same as minimum
        // remove it from min stack also
        if(st.top() == minSt.top()) {
            minSt.pop();
        }

        // Remove from main stack
        st.pop();
    }

    // Return top element
    int top() {
        return st.top();
    }

    // Return minimum element in stack
    int getMin() {
        return minSt.top();
    }
};
