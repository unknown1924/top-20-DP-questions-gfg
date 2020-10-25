/*
    Consider a row of n coins of values v1 . . . vn, where n is even. 
    We play a game against an opponent by alternating turns. 
    In each turn, a player selects either the first or last coin from the row, 
    removes it from the row permanently,and receives the value of the coin. 
    Determine the maximum possible amount of money we can definitely win if we move first. 

F(i, j) represents the maximum value the user
can collect from i'th coin to j'th coin. [Vi = value at ith coin]

F(i, j) = Max(Vi + min(F(i+2, j), F(i+1, j-1) ), 
              Vj + min(F(i+1, j-1), F(i, j-2) ))
As user wants to maximise the number of coins. 

Base Cases:
    F(i, j) = Vi           If j == i
    F(i, j) = max(Vi, Vj)  If j == i + 1 
*/

#include <bits/stdc++.h>
using namespace std;

int rec(vector<int> a, int i, int j){
    if(i+1 == j)
       return max(a[i], a[j]);
    else if(i == j)
        return a[i];
    return max(a[i] + min(rec(a, i+2, j), rec(a, i+1, j-1)), a[j] + min(rec(a, i, j-2), rec(a, i+1, j-1)));
}

int max_score_recursive(vector<int> a){
    int n = a.size();
    int sum = 0;
    return rec(a, 0, n-1);
}

int max_score_dp(vector<int> a){
    int n = a.size();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for(int k = 0; k < n; k++){
        for(int i = 0, j = k; j < n; i++, j++){
        // similar to recursive one
            dp[i][j] = max(a[i] + min(dp[i+2][j], dp[i+1][j-1]),
                           a[j] + min(dp[i][j-2], dp[i+1][j-1]));
        }
    }
// print the matrix
    //for(int i = 0; i < n; i++){
    //    for(int j = 0; j < n; j++){
    //        cout << dp[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    return dp[0][n-1];
}

int main(){
    vector<int> a{8, 15, 3, 7};
    vector<int> b{ 20, 30, 2, 2, 2, 10 };
    cout << max_score_recursive(a) << endl;
    cout << max_score_dp(b) << endl;
}
