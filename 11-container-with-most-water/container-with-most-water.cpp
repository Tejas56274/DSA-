class Solution {
public:
    // Two‑pointer approach: start from both ends and move the shorter side inward.
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int maxWater = 0;
        while (left < right) {
            int width = right - left;
            int currentHeight = std::min(height[left], height[right]);
            int currentWater = width * currentHeight;
            maxWater = std::max(maxWater, currentWater);
            // Move the pointer at the shorter line because only that can possibly increase area.
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxWater;
    }
};