#include <vector>
#include <algorithm>

class Solution {
public:
    // Returns the maximum area of water that can be contained.
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int currentHeight = std::min(height[left], height[right]);
            maxWater = std::max(maxWater, width * currentHeight);

            // Move the pointer at the shorter line inward,
            // because only a taller line could increase the area.
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxWater;
    }
};