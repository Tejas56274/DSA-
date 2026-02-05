class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
       
        vector<int>nsgt(arr.size(),0);
           stack<int>st;
         for(int i=arr.size()-1;i>=0;i--)
         {
       
            while(!st.empty() && arr[st.top()]<=arr[i])
            {
                
                st.pop();
            }
            if(!st.empty())
            {
                  nsgt[i] = st.top() - i;
            }
           st.push(i);
          
            
         }
         return nsgt ;
    }

};