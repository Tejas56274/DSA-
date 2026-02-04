class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int i = 0, j=0,ml = 0;

        while(j<s.size()) {
            mp[s[j]]++;

            // repeat char aaya
            while(mp[s[j]] > 1) {
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            
            ml = max(ml, j - i + 1);
            j++;
        }
        return ml;
    }
};
