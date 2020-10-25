/*  Given weights and values of n items, put these items in a knapsack 
    of capacity W to get the maximum total value in the knapsack.   */

#include <bits/stdc++.h>
using namespace std;

int max_value_util(vector<int> v, vector<int> w, int W, int i){
    if(W <= 0) return 0;
    if(i == 0)  return v[i];
    if(w[i] > W) return max_value_util(v, w, W, i-1);
    return max(v[i] + max_value_util(v, w, W-w[i], i-1), max_value_util(v, w, W, i-1));
}
    // Recursive solution
int max_value_recursive(vector<int> value, vector<int> weight, int W){
    int n = weight.size();
        // call utility recursive function
    return max_value_util(value, weight, W, n-1);
}

    // Iterative solution ( DP )
int max_value_dp(vector<int> value, vector<int> weight, int W){
    int n = weight.size();
    int dp[n+1][W+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0 or w == 0)
                dp[i][w] = 0;
            else if(weight[i-1] <= W)
                    // choosing current element or NOT choosing 
                dp[i][w] = max(value[i-1] + dp[i-1][w - weight[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

int main(){
    vector<int> value { 60, 100, 120 };
    vector<int> weight { 10, 20, 30 };
    int W = 50;

    cout << "\nGiven values: " << endl;
    for(int e : value) cout << e <<' ';

    cout << "\n\nCorresponding weights: " << endl;
    for(int e : weight) cout << e << ' ';

    cout << "\n\nTotal Capacity of knapsack: " << W << endl;

    cout << "Recursive Soln: " << max_value_recursive(value, weight, W) << endl;
    cout << "DP soln: " << max_value_dp(value, weight, W) << endl;
}
