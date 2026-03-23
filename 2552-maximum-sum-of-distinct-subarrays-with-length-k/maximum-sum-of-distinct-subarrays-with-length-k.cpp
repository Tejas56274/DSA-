class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0,maxsum=0;
        int i=0,j=0;
        unordered_map<int,int>mp;
        while(j<nums.size())
        {
            sum+=nums[j];
            mp[nums[j]]++;
      
            if(j-i+1>k)
            {
                sum-=nums[i];
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            if(j-i+1==k)
            {
                if(mp.size()==k)
                {
                   maxsum=max(maxsum,sum);
                }
            }

            j++;
            
        }
        return maxsum;
    }
};