#include <bits/stdc++.h>
using namespace std;

int lcs_util(string a, string b, int i, int j){
    if(i < 0 or j < 0)
        return 0;
    if(a[i] == b[j])
        return 1 + lcs_util(a, b, i-1, j-1); 
    return max(lcs_util(a, b, i-1, j), lcs_util(a, b, i, j-1));
}

int lcs_recursive(string a, string b){
    return lcs_util(a, b, a.length()-1, b.length()-1);
}

int lcs_dp(string a, string b){
    int n = a.length();     int m = b.length();
    int dp[n+1][m+1] = {0};
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int shortest_common_subsequence(string a, string b){
    int n = a.length();     int m = b.length();
    //int l = lcs_dp(a, b);
    int l = lcs_dp(a, b);
    return (n + m - l);
}

int main(){
    //string a = "geek", b = "eke";
    string a = "AGGTAB",  b = "GXTXAYB";
    // returns the lengths 
    cout << lcs_recursive(a, b) << endl;
    cout << lcs_dp(a, b) << endl;
    cout << shortest_common_subsequence(a, b) << endl;
}
