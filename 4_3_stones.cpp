**************************************************** START ************************************************************
 

/*Q3. There's a cost of removing stone, the cost is different if it has one neighbour,
 two neighbours and it's zero if no neighbour.
Within a given sequence of stones, find minimum cost to remove all of them.
 Each stone had different costs for each neighbour condition 

 https://codeforces.com/blog/entry/117311
 see comments (approach by vgtcross)
*/

 // Question Link :- https://codeforces.com/problemset/problem/358/D

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, vector<int> &b, vector<int> &c, int n){
    
    if(n<=1)
    return a[0];
    
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    
    for(int i=1; i<n; i++){
        dp[i][0] = max(dp[i-1][0]+b[i], dp[i-1][1]+a[i]);
        dp[i][1] = max(dp[i-1][1]+b[i], dp[i-1][0] + c[i]);
    }
    
    return dp[n-1][0];
}


int main(){
    
    int n;
    cin>>n;
    
    vector<int> a(n), b(n), c(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    for(int i=0; i<n; i++){
        cin>>c[i];
    }
    
    int ans= solve(a, b, c, n);
    cout<<ans;
    
    
    
    return 0;
}

************************************************************* DONE *******************************************************
