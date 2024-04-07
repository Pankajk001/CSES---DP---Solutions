#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    int n, x;
    cin>>n>>x;

    vector<int>v(n);
    for(auto &i: v) cin>>i;

    vector<vector<int>>dp(n+1, vector<int>(x+1));
    //dp[i][k] = number of ways to get sum k 
    // such that all coins before coins[i] are not usable 
    // and all coins from i to n-1 are usable

    //base case
    for(int i = 0; i<n; i++){
        dp[i][0] = 1; //construct sum = 0 such that all coins from i to n-1 are pickable
    }

    //dp[i][k] is dependent on -> dp[i][k - some value], dp[i+1][k]

    for(int i = n-1; i>=0; i--){
        for(int sum = 1; sum <= x; sum++){

            //find dp[i][sum] -> dp[i+1][sum]
            int skipping = dp[i+1][sum];

            //when u pick up coin i
            int picking = 0;
            if(v[i] <= sum){
                picking = dp[i][sum - v[i]];
            }

            dp[i][sum] = (skipping + picking) % MOD;
        }
    }

    cout<<dp[0][x]<<endl;
    
    return 0;
}
