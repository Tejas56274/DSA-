#include <vector>
#include <algorithm>

class Solution {
public:
    // Use a const reference to avoid copying the input vector.
    int shipWithinDays(const std::vector<int>& weights, int D) {
        int min_cap = 0;               // Minimum possible capacity (max single weight)
        int max_cap = 0;               // Maximum possible capacity (sum of all weights)
        for (int w : weights) {
            min_cap = std::max(min_cap, w);
            max_cap += w;
        }

        // Binary search between min_cap and max_cap inclusive.
        while (min_cap < max_cap) {
            int mid = min_cap + (max_cap - min_cap) / 2; // candidate capacity
            int days_needed = 1;
            int cur_sum = 0;
            for (int w : weights) {
                if (cur_sum + w > mid) { // need a new day
                    ++days_needed;
                    cur_sum = 0;
                }
                cur_sum += w;
            }
            if (days_needed > D) {
                // Too few days, increase capacity.
                min_cap = mid + 1;
            } else {
                // Can ship within D days, try smaller capacity.
                max_cap = mid;
            }
        }
        return min_cap;
    }
};