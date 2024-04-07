/* Pankaj Sah */
#include <bits/stdc++.h>
// #define int long long
#define MOD 1000000007
#define MOD1 998244353
using namespace std;


int main(){
    int n;
    cin>>n;

    vector<vector<char>>grid(n, vector<char>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>grid[i][j];
        }
    }


    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

    if(grid[n-1][n-1] == '.') dp[n-1][n-1] = 1;
    else dp[n-1][n-1] = 0;

    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(i == n-1 and j == n-1) continue;
            if(grid[i][j] == '*') dp[i][j] = 0;
            else dp[i] [j] =( (dp[i+1][j])%MOD + (dp[i][j+1])%MOD)%MOD;
        }
    }

    cout<<dp[0][0]<<endl;

    return 0;
}