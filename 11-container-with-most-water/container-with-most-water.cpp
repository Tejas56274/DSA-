class Solution {
public:
    int maxArea(const std::vector<int>& height) {
        int maxWater = 0;
        std::size_t left = 0;
        std::size_t right = height.size() - 1;
        while (left < right) {
            int current = static_cast<int>((right - left) * std::min(height[left], height[right]));
            maxWater = std::max(maxWater, current);
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxWater;
    }
};