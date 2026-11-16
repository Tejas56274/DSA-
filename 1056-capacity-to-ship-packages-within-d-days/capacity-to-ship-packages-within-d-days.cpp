#include <vector>
#include <algorithm>

class Solution {
public:
    // Binary search the minimal ship capacity that allows shipping within D days.
    int shipWithinDays(std::vector<int>& weights, int D) {
        int lower = 0;               // minimal possible capacity
        int upper = 0;               // maximal possible capacity (sum of all weights)

        for (int w : weights) {
            lower = std::max(lower, w); // at least the heaviest package
            upper += w;                 // sum of all packages
        }

        while (lower < upper) {
            int mid = lower + (upper - lower) / 2;
            int daysNeeded = 1;
            int currentLoad = 0;

            for (int w : weights) {
                if (currentLoad + w > mid) {
                    ++daysNeeded;
                    currentLoad = 0;
                }
                currentLoad += w;
            }

            if (daysNeeded > D) {
                lower = mid + 1; // need more capacity
            } else {
                upper = mid;     // mid capacity works, try smaller
            }
        }
        return lower;
    }
};