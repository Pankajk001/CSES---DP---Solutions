/* Pankaj Sah */
#include <bits/stdc++.h>
// #define int long long
#define MOD 1000000007
#define MOD1 998244353
using namespace std;

bool isValid(int prev, int m){
    if(prev >= 1 and prev <= m) return true;
    else return false;
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<int>a(n);
    for(auto &x: a) cin>>x;

    vector<vector<int>>dp(n+1, vector<int>(m + 1));
    //dp[i][k] = number of ways to build a prefix of size i 
    //such that the last element of the prefix is k

    //base case dp[1][k] = 1 if (a[0] == 0 or a[0] == k)
    for(int i = 1; i<=m; i++){
        if(a[0] == i || a[0] == 0){
            dp[1][i] = 1;
        }
    }

    for(int i = 2; i<= n; i++){
        for(int k = 1; k<=m; k++){
            //finding dp[i][k] here
            if(a[i-1] != 0 and a[i-1] != k){
                dp[i][k] = 0;
                continue;
            }

            for(int prev = k - 1; prev <= k + 1; prev++){
                if(!isValid(prev, m)) continue;
                
                //transition
                dp[i][k] = (dp[i][k] + dp[i-1][prev])%MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i<=m; i++){
        ans = (ans + dp[n][i])%MOD;
    }

    cout<<ans<<endl;
}
