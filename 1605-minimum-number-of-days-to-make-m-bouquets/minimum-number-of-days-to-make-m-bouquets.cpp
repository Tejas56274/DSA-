class Solution {
public:
    bool isPossible(vector<int>& arr, int day, int m, int k) {
        int count = 0;
        int bouquets = 0;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] <= day) {
                count++;
                if(count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& arr, int m, int k) {
        long long n = arr.size();
        if(n < (long long)m * k) return -1;

        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(arr, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
