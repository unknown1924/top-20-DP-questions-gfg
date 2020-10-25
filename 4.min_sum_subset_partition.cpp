/*
 Partition a set into two subsets such that the difference of subset 
 sums is minimum
*/

#include <bits/stdc++.h>
using namespace std;

int find_min_sum(vector<int> a, int i, int sum_calculated, int sum_total){
    if(i == 0) return abs((sum_total - sum_calculated) - sum_calculated);
            // find min of the two possible cases
    return min(
            // include a[i-1] in first set
                find_min_sum(a, i-1, sum_calculated+a[i-1], sum_total),
            // do not include a[i-1] in the first set
                find_min_sum(a, i-1, sum_calculated, sum_total)
              );
}
int solve_recursive(vector<int> a){
    int n = a.size();
    int sum_total = 0;
    for(int e : a)
        sum_total += e;
    return find_min_sum(a, n, 0, sum_total);
}

int solve_dp(vector<int> a){
    int n = a.size();
    int sum = 0;
    // get total sum
    for(int e : a)
        sum += e;

    int dp[n+1][sum+1];

// dp[0][0] = 1 always
// possible to get 0 sum
    for(int i = 0; i <= n; i++) dp[i][0] = 1;

// 0 sum not possible
    for(int i = 1; i <= sum; i++) dp[0][i] = 0;


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            dp[i][j] = dp[i-1][j];
            if(a[i-1] <= j)
                dp[i][j] |= dp[i-1][j - a[i-1]];

        }
    }
/*
    // for printing dp table
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
*/
    int diff = INT_MAX;
    for(int i = (sum)/2; i >= 0; i--){
        if(dp[n][i] == 1){
            diff = sum - 2*i;
            break;
        }
    }

    return diff;
}

int main(){
    vector<int> a{1, 6, 11, 5};
    //vector<int> a{1, 5 ,7, 10};
    cout << "Given Array: " ;
    for(int e : a) cout << e << ' ';
    cout << endl;
    cout << "Solved with DP: " ;
    cout << solve_dp(a) << endl;
    cout << "Solved with recursion: " ;
    cout << solve_recursive(a) << endl;
}
