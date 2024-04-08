/* Pankaj Sah */
#include <bits/stdc++.h>
// #define int long long
#define MOD 1000000007
#define MOD1 998244353
using namespace std;


int main(){
    int n, x;
    cin>>n>>x;

    vector<int>price(n), pages(n);
    for(auto &i: price) cin>>i;
    for(auto &i: pages) cin>>i;

    vector<vector<int>>dp(n + 1, vector<int>(x+1, 0));
    //dp[i][j] = max value that can be attained from i elements 
    //such that j weight is allowed to be used

    dp[0][x] = 0;  //when 0 elements are left

    for(int i = 1; i<=n; i++){
        for(int j = 0; j <= x; j++){
            int w = price[i - 1];
            int val = pages[i - 1];

            int pick = (j >= w ? val + dp[i-1][j - w] : 0);
            int skip = dp[i-1][j];

            dp[i][j] = max(pick, skip);
        }
    }

    cout<<dp[n][x]<<endl;

    
    return 0;
}