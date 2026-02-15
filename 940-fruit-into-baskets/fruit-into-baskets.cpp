class Solution {
public:
    int totalFruit(vector<int>& s) {
        int i = 0, j = 0, maxLen = 0;
        unordered_map<int, int> basket;

        while (j < s.size()) {
            basket[s[j]]++;

           
            while (basket.size() > 2) {
                basket[s[i]]--;
                if (basket[s[i]] == 0)
                    basket.erase(s[i]);
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};