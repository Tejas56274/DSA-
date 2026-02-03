class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
     vector<int>nse(arr.size());
       stack<int>st;
       
       for(int i=arr.size()-1;i>=0;i--)
       {
           int curr=arr[i];
           while(!st.empty()&&st.top()>=curr)
           {
               st.pop();
           }
           nse[i]=st.empty() ? -1 : st.top();
           st.push(curr);
       }
       return nse;
        
    }
};