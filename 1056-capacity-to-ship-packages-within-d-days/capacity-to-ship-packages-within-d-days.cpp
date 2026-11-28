#include <vector>
#include <algorithm>

class Solution {
public:
    // Returns the minimal ship capacity needed to ship all packages within D days.
    int shipWithinDays(std::vector<int>& weights, int D) {
        int min_cap = 0; // at least the heaviest package
        int max_cap = 0; // at most the sum of all packages
        for (int w : weights) {
            min_cap = std::max(min_cap, w);
            max_cap += w;
        }

        // Binary search between min_cap and max_cap (inclusive lower bound)
        while (min_cap < max_cap) {
            int mid = min_cap + (max_cap - min_cap) / 2; // candidate capacity
            int days_needed = 1;
            int cur_load = 0;
            for (int w : weights) {
                if (cur_load + w > mid) {
                    ++days_needed; // need a new day
                    cur_load = 0;
                }
                cur_load += w;
            }
            if (days_needed > D) {
                // Capacity too small, need to increase lower bound
                min_cap = mid + 1;
            } else {
                // Capacity sufficient, try smaller upper bound
                max_cap = mid;
            }
        }
        return min_cap;
    }
};