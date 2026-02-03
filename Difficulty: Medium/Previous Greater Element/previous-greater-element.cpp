class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        //  code here
        vector<int>nse(arr.size());
       stack<int>st;
       
       for(int i=0;i<arr.size();i++)
       {
           int curr=arr[i];
           while(!st.empty()&&st.top()<=curr)
           {
               st.pop();
           }
           nse[i]=st.empty() ? -1 : st.top();
           st.push(curr);
       }
       return nse;
    }
};