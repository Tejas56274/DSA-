class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int currsum=0,count=0;
    for(int num:nums)
    {
        currsum+=num;
        if(mp.find(currsum-k)!=mp.end())
        {
            count+=mp[currsum-k];
        }
        mp[currsum]++;
    }
    return count;
    }
};