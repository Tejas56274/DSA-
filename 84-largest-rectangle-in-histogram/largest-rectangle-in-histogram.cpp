class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> nsr(n), nsl(n);
        stack<int> st;

        
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && h[st.top()] >= h[i])
                st.pop();

            nsr[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        
        while(!st.empty()) st.pop();

    
        for(int i = 0; i < n; i++) {
            while(!st.empty() && h[st.top()] >= h[i])
                st.pop();

            nsl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

    
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            int width = nsr[i] - nsl[i] - 1;
            int area = h[i] * width;
            maxi = max(maxi, area);
        }

        return maxi;
    }
};
