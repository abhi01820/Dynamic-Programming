#include <bits/stdc++.h>
using namespace std;

class Recursion {
public:
    int solve(int n){
        if(n == 0) return 0;
        int ans = INT_MAX;
        for(int i = 1; i * i <= n; i++){
            ans = min(ans, 1 + solve(n - i*i));
        }
        return ans;
    }

    int numSquares(int n) {
        return solve(n);
    }
};

class Memoization {
public:
    vector<int> dp;

    int solve(int n){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];

        int ans = INT_MAX;
        for(int i = 1; i * i <= n; i++){
            ans = min(ans, 1 + solve(n - i*i));
        }

        return dp[n] = ans;
    }

    int numSquares(int n) {
        dp.assign(n + 1, -1);
        return solve(n);
    }
};

class Tabulation {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j * j <= i; j++){
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
            }
        }

        return dp[n];
    }
};

class SpaceOptimized {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j * j <= i; j++){
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
            }
        }

        return dp[n];
    }
};
