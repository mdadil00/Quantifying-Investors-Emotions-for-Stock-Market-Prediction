#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<long long>
#define pb push_back

#define f(it,a) for(auto &it:a)



int mod=1e9+7;

int main(){
fast
int n,sum; cin>>n>>sum;
vi coins(n); f(it,coins) cin>>it;

vector<vector<int>> dp(n+1,vector<int>(sum+1,0));

for (int i = 0; i < n+1; i++)
{
    dp[i][0]=1;
}


for (int i = 1; i < n+1; i++)
{
    for (int j = 1; j < sum+1; j++)
    {
        if(j>=coins[i-1]) dp[i][j]=(dp[i][j-coins[i-1]]+dp[i-1][j])%mod;
        else dp[i][j]=dp[i-1][j]%mod;
    }
}

cout<<dp[n][sum]%mod;

return 0;
}