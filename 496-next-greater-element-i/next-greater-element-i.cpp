class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>nge;
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            int curr=nums2[i];
            while(!st.empty() && st.top()<=nums2[i])
            {
                st.pop();
            }
            nge[curr]=st.empty() ? -1:st.top();
            st.push(curr);

        }

        vector<int>ans;
        for(int x:nums1)
        {
            ans.push_back(nge[x]);
        }
        return ans;
    }
};