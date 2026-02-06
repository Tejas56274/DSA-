class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int R = matrix.size();
        int C = matrix[0].size();

        // column-wise prefix sum
        vector<vector<int>> pref(R+1, vector<int>(C, 0));

        for(int i = 1; i <= R; i++) {
            for(int j = 0; j < C; j++) {
                pref[i][j] = pref[i-1][j] + (matrix[i-1][j] == '1');
            }
        }

        int ans = 0;

        // fix top row
        for(int top = 0; top < R; top++) {
            // fix bottom row
            for(int bottom = top; bottom < R; bottom++) {

                int width = 0;
                int height = bottom - top + 1;

                for(int col = 0; col < C; col++) {

                    // check if column fully filled with 1s between top..bottom
                    if(pref[bottom+1][col] - pref[top][col] == height) {
                        width++;
                        ans = max(ans, width * height);
                    } else {
                        width = 0;
                    }
                }
            }
        }

        return ans;
    }
};
