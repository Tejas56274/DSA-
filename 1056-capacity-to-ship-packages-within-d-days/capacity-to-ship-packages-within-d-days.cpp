#include <vector>
#include <algorithm>

class Solution {
public:
    int shipWithinDays(const std::vector<int>& weights, int D) {
        int min_cap = 0;
        int max_cap = 0;
        for (int weight : weights) {
            min_cap = std::max(min_cap, weight);
            max_cap += weight;
        }

        while (min_cap < max_cap) {
            int mid = min_cap + (max_cap - min_cap) / 2;
            int days_needed = 1;
            int current_load = 0;
            for (int weight : weights) {
                if (current_load + weight > mid) {
                    ++days_needed;
                    current_load = 0;
                }
                current_load += weight;
            }
            if (days_needed > D) {
                min_cap = mid + 1;
            } else {
                max_cap = mid;
            }
        }
        return min_cap;
    }
};