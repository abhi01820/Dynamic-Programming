


#include <bits/stdc++.h>
using namespace std;

/*
    FIBONACCI USING 4 METHODS
    1) Recursion (Brute Force)
    2) Memoization (Top Down DP)
    3) Tabulation (Bottom Up DP)
    4) Space Optimization (Best)
*/


// -----------------------------------------------------
// 1) RECURSION (BRUTE FORCE)
// -----------------------------------------------------
int fib_recursion(int n)
{
    if(n <= 1)
        return n;

    return fib_recursion(n-1) + fib_recursion(n-2);
}



// -----------------------------------------------------
// 2) MEMOIZATION (TOP-DOWN DP)
// -----------------------------------------------------
int fib_memo_helper(int n, vector<int> &dp)
{
    if(n <= 1)
        return n;

    // already calculated
    if(dp[n] != -1)
        return dp[n];

    // store and return
    return dp[n] = fib_memo_helper(n-1, dp) + fib_memo_helper(n-2, dp);
}

int fib_memoization(int n)
{
    vector<int> dp(n+1, -1);
    return fib_memo_helper(n, dp);
}



// -----------------------------------------------------
// 3) TABULATION (BOTTOM-UP DP)
// -----------------------------------------------------
int fib_tabulation(int n)
{
    if(n <= 1)
        return n;

    vector<int> dp(n+1, 0);

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}



// -----------------------------------------------------
// 4) SPACE OPTIMIZATION (BEST)
// -----------------------------------------------------
int fib_space_optimized(int n)
{
    if(n <= 1)
        return n;

    int prev = 1;   // dp[i-1]
    int pPrev = 0;  // dp[i-2]

    for(int i=2; i<=n; i++)
    {
        int curr = prev + pPrev;
        pPrev = prev;
        prev = curr;
    }

    return prev;
}



// -----------------------------------------------------
// MAIN DRIVER (for testing)
// -----------------------------------------------------
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "\nRecursion: " << fib_recursion(n) << endl;
    cout << "Memoization: " << fib_memoization(n) << endl;
    cout << "Tabulation: " << fib_tabulation(n) << endl;
    cout << "Space Optimized: " << fib_space_optimized(n) << endl;

    return 0;
}





