class Solution {
public:
    int shipWithinDays(const std::vector<int>& weights, int D) {
        // Determine the lower and upper bounds for binary search.
        int lower = 0; // Minimum possible capacity (at least the heaviest package).
        int upper = 0; // Maximum possible capacity (sum of all packages).
        for (int w : weights) {
            lower = std::max(lower, w);
            upper += w;
        }

        // Binary search for the smallest capacity that allows shipping within D days.
        while (lower < upper) {
            int mid = lower + (upper - lower) / 2; // Candidate capacity.
            int daysNeeded = 1;
            int currentLoad = 0;
            for (int w : weights) {
                if (currentLoad + w > mid) {
                    ++daysNeeded;   // Need an extra day.
                    currentLoad = 0; // Reset load for the new day.
                }
                currentLoad += w;
            }
            if (daysNeeded > D) {
                // Capacity too small, need to increase lower bound.
                lower = mid + 1;
            } else {
                // Capacity sufficient, try to find a smaller one.
                upper = mid;
            }
        }
        return lower;
    }
};