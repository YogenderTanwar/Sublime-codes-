// forest dp grid dp
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n + 1, vector<int> (m, 0));

        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
            if (j) dp[0][j] += dp[0][j - 1];
        }

        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0];
            if (i) dp[i][0] += dp[i - 1][0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i][j]);
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (matrix[i][j]) {
                    ans++;
                    int k = 2;
                    while ((i + k - 1) < n && (j + k - 1) < m)
                    {
                        int val = (dp[i + k - 1][j + k - 1]);
                        if ((j - 1) >= 0) val -= (dp[i + k - 1][j - 1]);
                        if ((i - 1) >= 0) val -= (dp[i - 1][j + k - 1]);

                        if ((i - 1) >= 0 && (j - 1) >= 0 ) val += (dp[i - 1][j - 1]);

                        if (val == (k * k)) {
                            ans++, k++;
                        }
                        else break;
                    }

                }
            }
        }


        return ans;


    }
};