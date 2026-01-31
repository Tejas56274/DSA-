class Solution {
public:
    bool isValid(vector<int>& arr, int k, int mid) {
        int students = 1;
        int pages = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > mid) return false;

            if (pages + arr[i] <= mid) {
                pages += arr[i];
            } else {
                students++;
                pages = arr[i];

                if (students > k) return false;
            }
        }
        return true;
    }

    int minTime(vector<int>& arr, int k)
 {
        int n = arr.size();
        if (k > n) return -1;

        int low = 0, high = 0;
        for (int x : arr) {
            low = max(low, x);
            high += x;
        }

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValid(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
