class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp; // sum -> first index
        mp[0] = -1;                 // sum = 0 before starting
        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                sum += 1;
            else
                sum -= 1;

            if (mp.find(sum) != mp.end()) {
                // sum pehle bhi aaya — equal 0s aur 1s mile
                int len = i - mp[sum];
                if (len > maxLen)
                    maxLen = len;
            } else {
                // pehli baar ye sum mila
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};
