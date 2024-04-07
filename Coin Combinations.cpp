#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    int n, x;
    cin>>n>>x;

    vector<int>v(n);
    for(auto &i: v) cin>>i;

    vector<int>dp(x+1, 0);
    dp[0] = 1;
    // dp[i] = no of ways to create a sum of i 
    for(int i = 1; i<=x; i++){
        for(int j = 0; j<n; j++){
            if(v[j] <= i){
                dp[i]  = (dp[i] + dp[i - v[j]])%MOD;
            }
        }
    }

    cout<<dp[x]<<endl;

    return 0;
}
