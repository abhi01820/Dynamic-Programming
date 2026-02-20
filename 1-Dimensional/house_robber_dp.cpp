#include <bits/stdc++.h>
using namespace std;

/*
    HOUSE ROBBER - 4 APPROACHES

    Problem:
    You are given an array where nums[i] is money in the i-th house.
    You cannot rob two adjacent houses.
    Return maximum money you can rob.
*/


// -----------------------------------------------------
// 1) RECURSION (Brute Force)
// -----------------------------------------------------
int rob_recursion(int idx, vector<int>& nums) {
    if(idx == 0) return nums[0];
    if(idx < 0) return 0;

    int take = nums[idx] + rob_recursion(idx - 2, nums);
    int notTake = rob_recursion(idx - 1, nums);

    return max(take, notTake);
}


// -----------------------------------------------------
// 2) MEMOIZATION (Top Down DP)
// -----------------------------------------------------
int rob_memo_helper(int idx, vector<int>& nums, vector<int>& dp) {
    if(idx == 0) return nums[0];
    if(idx < 0) return 0;

    if(dp[idx] != -1)
        return dp[idx];

    int take = nums[idx] + rob_memo_helper(idx - 2, nums, dp);
    int notTake = rob_memo_helper(idx - 1, nums, dp);

    return dp[idx] = max(take, notTake);
}

int rob_memoization(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return rob_memo_helper(n - 1, nums, dp);
}


// -----------------------------------------------------
// 3) TABULATION (Bottom Up DP)
// -----------------------------------------------------
int rob_tabulation(vector<int>& nums) {
    int n = nums.size();

    if(n == 1) return nums[0];

    vector<int> dp(n, 0);
    dp[0] = nums[0];

    for(int i = 1; i < n; i++) {
        int take = nums[i];
        if(i > 1)
            take += dp[i - 2];

        int notTake = dp[i - 1];

        dp[i] = max(take, notTake);
    }

    return dp[n - 1];
}


// -----------------------------------------------------
// 4) SPACE OPTIMIZATION (Most Optimal)
// -----------------------------------------------------
int rob_space_optimized(vector<int>& nums) {
    int n = nums.size();

    if(n == 1) return nums[0];

    int pPrev = 0;        // dp[i-2]
    int prev = nums[0];   // dp[i-1]

    for(int i = 1; i < n; i++) {
        int take = nums[i] + pPrev;
        int notTake = prev;

        int curr = max(take, notTake);

        pPrev = prev;
        prev = curr;
    }

    return prev;
}


// -----------------------------------------------------
// MAIN FUNCTION (for local testing)
// -----------------------------------------------------
int main() {
    int n;
    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter money in each house: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "\nRecursion: " << rob_recursion(n - 1, nums) << endl;
    cout << "Memoization: " << rob_memoization(nums) << endl;
    cout << "Tabulation: " << rob_tabulation(nums) << endl;
    cout << "Space Optimized: " << rob_space_optimized(nums) << endl;

    return 0;
}
