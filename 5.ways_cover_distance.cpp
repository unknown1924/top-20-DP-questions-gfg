#include <bits/stdc++.h>
using namespace std;

int solve_recursive(int n){
    if(n < 0) return 0;
    if(n == 0) return 1;
    // return the sum of ways
    return solve_recursive(n-1) + solve_recursive(n-2) + solve_recursive(n-3);
}


int solve_dp(int n){
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}

int main(){
    int n = 4;
    // cover distance n with steps 1, 2, 3
    // find total no of ways of doing so
    cout << "Recursive sol: " ;
    cout << solve_recursive(n) << endl;
    cout << "DP sol: ";
    cout << solve_dp(n) << endl;
}
