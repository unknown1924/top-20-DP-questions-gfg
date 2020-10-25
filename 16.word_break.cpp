#include <bits/stdc++.h>
using namespace std;

int dictionaryContains(string word){
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    for(int i = 0; i < n; i++)
        if(dictionary[i].compare(word) == 0)
            return true;
    return false;
}

int wordbreak_recursive(string str){
    int n = str.size();
    if(n == 0) return true;

    for(int len = 1; len <= n; len++){
        if(dictionaryContains(str.substr(0, len)) and wordbreak_recursive(str.substr(len, n-len)))
            return true;
    }
    return false;
}

int wordbreak_dp(string str){
    int n = str.size();
    if(n == 0) return true;
    bool dp[n+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++){
        if(dp[i] == false and dictionaryContains(str.substr(0, i)))
            dp[i] = true;
        if(dp[i] == true){
            if(i == n) return true;
            for(int j = i+1; j <= n; j++){
                if(dp[j] == false and dictionaryContains(str.substr(i, j-1)))
                    dp[j] = true;
                if(j == n and dp[j] == true)
                    return true;
            }
        }
    }
    return false;
}

int main(){
    cout << "\nWordBreak solution with Recursion and DP: " << endl;
    cout << "ilikesamsung : " << endl << wordbreak_recursive("ilikesamsung") << endl;
    cout << wordbreak_dp("ilikesamsung");
}
