class Solution {
public:
    int maxArea(const vector<int>& height) {
        int l = 0, r = height.size() - 1, maxwater = 0;
        while (l < r) {
            int w = r - l;
            int ht = min(height[l], height[r]);
            int currwater = w * ht;
            maxwater = max(maxwater, currwater);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return maxwater;
    }
};