class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        for(int c:s)
        {
            if(c=='(')
            {
                st.push(')');
            }
        else  if(c=='[')
            {
                st.push(']');
            }
            else if(c=='{')
            {
                st.push('}');
            }
            else if(st.empty() || st.top()!=c)
            {
                return false;
            }
            else{st.pop();}
            
        }
        return st.empty();
    }
};