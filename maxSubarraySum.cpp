int maxSubarraySum(int arr[], int n) {

  // Your code here

  int dp[n + 1][3];

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j < 3; j++) dp[i][j] = -1e9;

  }

  dp[0][0] = 0;

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (j < 2) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
      if (i < n)
      {
        dp[i + 1][j] = max(dp[i + 1][j], ((j == 1) ? arr[i] : 0) + dp[i][j]);

      }


    }
  }

  return dp[n][2];




}