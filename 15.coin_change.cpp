#include <bits/stdc++.h>
using namespace std;

int total_ways_util(int N, int m, vector<int> change){
    if(N == 0) return 1;
    if(N < 0) return 0;
    if(m <= 0  and N >= 1)  return 0;
    return total_ways_util(N, m-1, change) + total_ways_util(N-change[m-1], m, change);
}

int total_ways_recursive(int N, vector<int> change){
    int n = change.size();
    return total_ways_util(N, n, change);
}

int total_ways_dp(int N, vector<int> change){
    int m = change.size();
    int dp[m+1][N+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= m; i++)
        dp[i][0] = 1;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= N; j++){
            // choosing the ith coin
            if(change[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i][j-change[i-1]];
            // not choosing the ith coin
            else
                dp[i][j] = dp[i-1][j];
        }
    }

//  for(int i = 0; i <= m; i++){
//      for(int j = 0; j <= N; j++){
//          cout << dp[i][j] << ' ';
//      }
//      cout << endl;
//  }
    return dp[m][N];
}

// space optimized DP solution O(n)
int total_ways_space_optimized(int N, vector<int> change){
    int m = change.size();
    int dp[N+1] = {0};
    dp[0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = change[i]; j <= N; j++){
            dp[j] += dp[j-change[i]];
        }
    }
    return dp[N];
}

int main(){
    int N = 10;
    vector<int> change{2,5,3,6};
    cout << "\nCoin change: Recursive, DP, DP space optmized solution: " << endl;
    cout << total_ways_recursive(N, change) << endl;
    cout << total_ways_dp(N, change) << endl;
    cout << total_ways_space_optimized(N, change) << endl;
}
