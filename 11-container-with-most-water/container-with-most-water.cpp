class Solution {
public:
    int maxArea(const std::vector<int>& height) {
        // Use two pointers starting at both ends of the array.
        // Move the pointer pointing to the shorter line inward,
        // because the area is limited by the shorter height.
        size_t left = 0;
        size_t right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int currentHeight = std::min(height[left], height[right]);
            int currentWidth = static_cast<int>(right - left);
            int currentArea = currentHeight * currentWidth;
            maxArea = std::max(maxArea, currentArea);

            // Move the pointer at the shorter line inward to try a larger height.
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxArea;
    }
};