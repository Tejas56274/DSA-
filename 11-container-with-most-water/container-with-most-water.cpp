#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(const vector<int>& height) {
        int l = 0;
        int r = static_cast<int>(height.size()) - 1;
        int maxWater = 0;
        while (l < r) {
            int width = r - l;
            int h = min(height[l], height[r]);
            maxWater = max(maxWater, width * h);
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return maxWater;
    }
};