#include <bits/stdc++.h>
using namespace std;

// recursive util funtion
int cut_rod_util(int L, vector<int> price){
    int profit = 0;
    for(int i = 0; i < L; i++){
        // get the max profit at length
        profit = max(price[i] + cut_rod_util(L-i-1, price), profit);
    }
    return profit;
}

int cut_rod_recursion(int length, vector<int> price){
    return cut_rod_util(length, price);
}

// DP method
int cut_rod_dp(int length, vector<int> price){
    // Create a DP table of size length+1 and initialize all with 0
    int dp[length+1] = {0};
    
    // iterate over for all length from min 1 to max = length and
    // build the solution in a bottom up manner
    for(int i = 1; i <= length; i++){
        int profit = 0;
        // find the max profit at a particular length
        for(int j = 0; j < i; j++)
            profit = max(price[j] + dp[i-j-1], profit);
        // profit at length = i
        dp[i] = profit;
    }
    return dp[length];
}

int main(){
    int len = 8;
    vector<int> price{1, 5, 8, 9, 10, 17, 17, 20};
    cout << "\nSolution by recursion and by DP bottom up approach: " << endl;
    cout << cut_rod_recursion(len, price) << endl;
    cout << cut_rod_dp(len, price) << endl;
}
