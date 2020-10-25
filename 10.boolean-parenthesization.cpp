#include <bits/stdc++.h>
using namespace std;

int F(string b, string op, int i , int j);
int T(string b, string op, int i , int j);


int F(string b, string op, int i , int j){
    int n = b.length();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j <= n; j++){
            for(int k = i; k < j; k++){
                int tik = T(b, op, i, k) + F(b, op, i, k);
                int tkj = T(b, op, k+1, j) + F(b, op, k+1, j);
                if(op[k-1] == '&')
                    return F(b, op, i, k) * F(b, op, k+1, j);
                else if(op[k-1] == '|')
                    return (tik * tkj - T(b, op, i, k) * T(b, op, k+1, j));
                else
                    return (T(b, op, i, k) * T(b, op, k+1, j) + F(b, op, i, k) * F(b, op, k+1, j));
            }
        }
    }
    return 0;
}

int T(string b, string op, int i , int j){
    int n = b.length();
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            for(int k = i+1; k <= j; k++){
                int tik = T(b, op, i, k) + F(b, op, i, k);
                int tkj = T(b, op, k+1, j) + F(b, op, k+1, j);
                if(op[k-1] == '&')
                    return T(b, op, i, k) * T(b, op, k+1, j);
                else if(op[k-1] == '|')
                    return (tik * tkj - F(b, op, i, k) * F(b, op, k+1, j));
                else
                    return (T(b, op, i, k) * F(b, op, k+1, j) + F(b, op, i, k) * T(b, op, k+1, j));
            }
        }
    }
    return 0;
}

int count_ways(string b, string op){
    //int n = strlen(b);
    //int m = strlen(op);
    int n = b.length();
    int m = op.length();
    return T(b, op, 0, n);
}

int count_ways_dp(string b, string op, int n){
    int T[n][n], F[n][n];
    memset(T, 0, sizeof(T));    memset(F, 0, sizeof(F));
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            // hello world
        }
    }
    return 0;
}

int main(){
    //vector<bool> b{true, true, false, true};
    //vector<char> op{'|', '&', '^'};
    string b = "ttft";
    string op = "|&^";
    //cout << count_ways_dp(b, op, (int)b.length()) << endl;
    cout << count_ways(b, op) << endl;
}
