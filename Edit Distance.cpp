/* Pankaj Sah */
#include <bits/stdc++.h>
// #define int long long
#define MOD 1000000007
#define MOD1 998244353
using namespace std;

int main(){
    string a, b;
    cin>>a>>b;

    int n = a.length();
    int m = b.length();

    vector<vector<int>>dp(n+1, vector<int>(m+1, 1e6));
    //dp[i][j] = min steps to match the first i characters of first string
    // with first j characters of the second string

    //base case
    for(int i = 0; i <=n; i++){
        dp[i][0] = i; // first string has i characters and second string has finished
    }

    for(int j = 0; j<=m; j++){
        dp[0][j] = j; // second string has j characters remaining and first string has exhausted
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            char x = a[i-1];
            char y = b[j-1];

            //transition
            if(x == y){ //dont do anything
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = dp[i-1][j-1] + 1;
            }

            //skip ith character or add one character after jth character
            dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);

            //skip jth character or add one character after ith character
            dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
        }
    }

    cout<<dp[n][m]<<endl;
    return 0;
}