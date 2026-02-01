class Solution {
public:
    bool isValid(vector<int>& stalls, int k, int mid) {
        int cowCount = 1;
        int lastPos = stalls[0];

        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - lastPos >= mid) {
                cowCount++;
                lastPos = stalls[i];

                if(cowCount == k)
                    return true;
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int s = 0;
        int e = stalls.back() - stalls[0];
        int ans = -1;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(isValid(stalls, k, mid)) {
                ans = mid;
                s = mid + 1;   // try bigger distance
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};
