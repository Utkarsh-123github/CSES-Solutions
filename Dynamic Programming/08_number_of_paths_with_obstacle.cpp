#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<char>>arr(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    if(arr[0][0] == '*'){
        cout<<0;
    }
    else{
        vector<vector<long long int>>dp(n,vector<long long int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==n-1 && j==n-1){
                    dp[i][j] = 1;
                }
                else{
                    int down = 0;
                    int right = 0;
                    if(i<n-1 && arr[i+1][j] != '*'){
                        down = (down + dp[i+1][j])%mod;
                    }
                    if(j<n-1 && arr[i][j+1] != '*'){
                        right = (right + dp[i][j+1])%mod;
                    }
                    dp[i][j] = (down + right)%mod;
                }
            }
        }
        cout<<dp[0][0];
    }
    
    return 0;
}