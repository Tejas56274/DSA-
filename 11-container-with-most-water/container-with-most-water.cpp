#include <vector>
#include <algorithm>

class Solution {
public:
    // Accept the height array as a const reference to avoid copying.
    int maxArea(const std::vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int max_water = 0;

        while (left < right) {
            int width = right - left;
            int current_height = std::min(height[left], height[right]);
            int current_water = width * current_height;
            max_water = std::max(max_water, current_water);

            // Move the pointer at the shorter line inward.
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return max_water;
    }
};