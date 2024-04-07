#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    int n;
    cin>>n;
    
    vector<int>dp(n+1, 1e9);
    //dp[i] = minimum nuber of steps to convert i to 0

    dp[0] = 0; //base case

    for(int i = 1; i<=n; i++){
        string s = to_string(i);
        for(auto &x: s){
            int digit = x - '0';
            if(digit != 0){
                //transition step
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }
    }

    cout<<dp[n]<<endl;
    
    return 0;
}
