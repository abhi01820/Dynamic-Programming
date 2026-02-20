#include <bits/stdc++.h>
using namespace std;

/*
    CLIMBING STAIRS - 4 APPROACHES

    Problem:
    You can climb either 1 or 2 steps at a time.
    Find number of distinct ways to reach step n.
*/


// -----------------------------------------------------
// 1) RECURSION (Brute Force)
// -----------------------------------------------------
int climb_recursion(int n) {
    if(n <= 2) return n;

    return climb_recursion(n - 1) + climb_recursion(n - 2);
}


// -----------------------------------------------------
// 2) MEMOIZATION (Top-Down DP)
// -----------------------------------------------------
int climb_memo_helper(int n, vector<int>& dp) {
    if(n <= 2) return n;

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = climb_memo_helper(n - 1, dp) 
                 + climb_memo_helper(n - 2, dp);
}

int climb_memoization(int n) {
    vector<int> dp(n + 1, -1);
    return climb_memo_helper(n, dp);
}


// -----------------------------------------------------
// 3) TABULATION (Bottom-Up DP)
// -----------------------------------------------------
int climb_tabulation(int n) {
    if(n <= 2) return n;

    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}


// -----------------------------------------------------
// 4) SPACE OPTIMIZATION (Most Optimal)
// -----------------------------------------------------
int climb_space_optimized(int n) {
    if(n <= 2) return n;

    int pPrev = 1;  // ways to reach step 1
    int prev  = 2;  // ways to reach step 2

    for(int i = 3; i <= n; i++) {
        int curr = prev + pPrev;
        pPrev = prev;
        prev = curr;
    }

    return prev;
}


// -----------------------------------------------------
// MAIN FUNCTION (For Testing)
// -----------------------------------------------------
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "\nRecursion: " << climb_recursion(n) << endl;
    cout << "Memoization: " << climb_memoization(n) << endl;
    cout << "Tabulation: " << climb_tabulation(n) << endl;
    cout << "Space Optimized: " << climb_space_optimized(n) << endl;

    return 0;
}