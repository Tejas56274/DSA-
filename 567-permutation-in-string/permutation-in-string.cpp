class Solution {
public:
    bool checkInclusion(string p, string s) {
        if (s.size() < p.size()) return false;

        vector<int> freqP(26, 0), freqS(26, 0);

        for (char c : p) freqP[c - 'a']++;

        int window = p.size();
        for (int i = 0; i < s.size(); i++) {
            freqS[s[i] - 'a']++; // Add right char

            // Remove left char if window size exceeded
            if (i >= window)
                freqS[s[i - window] - 'a']--;

            // Compare only when window fully formed
            if (freqS == freqP)
               return true;
        }

        return false;
    }
};