// given a 2D matrix find the longest path with consecutive elements
#include <bits/stdc++.h>
using namespace std;

int longest_distance(vector<vector<int>> a, vector<vector<int>> dp, int i , int j){
    int n = a.size();   int m = a[0].size();

    if(i < 0 or i >= n or j < 0 or j >= m)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int x = INT_MIN;
    int y = INT_MIN;
    int w = INT_MIN;
    int z = INT_MIN;

    // for all direction
    if(j > 0 and (1 + a[i][j] == a[i][j-1]))
        x = 1 + longest_distance(a, dp, i, j-1);

    if(j < m-1 and (1 + a[i][j] == a[i][j+1]))
        y = 1 + longest_distance(a, dp, i, j+1);
    
    if(i > 0 and (1 + a[i][j] == a[i-1][j]))
        z = 1 + longest_distance(a, dp, i-1, j);

    if(i < n-1 and (1 + a[i][j] == a[i+1][j]))
        w = 1 + longest_distance(a, dp, i+1, j);

    dp[i][j] = max(x, max(y, max(z, max(w, 1))));

    return dp[i][j];
}

int longest_path_recursive(vector<vector<int>> a){
    int n = a.size();   int m = a[0].size();
        // memoize path len
    vector<vector<int>> dp(n, vector<int>(m, -1));

        // to store the max path length
    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
                // find max path len for each ccell
                // Basically a BFS search
            dp[i][j] = longest_distance(a, dp, i, j);
                // keep the max 
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> a = {{1, 2, 9},
                             {5, 3, 8},
                             {4, 6, 7}};

    cout << longest_path_recursive(a) << endl;
}

