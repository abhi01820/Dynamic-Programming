#include <bits/stdc++.h>
using namespace std;

/*-------------------------------------------------
1) RECURSION (Brute Force)  — O(2^n)
-------------------------------------------------*/
int solveRec(int i, int prev, vector<int>& nums){
    if(i == nums.size())
        return 0;

    int take = 0;
    if(prev == -1 || nums[prev] < nums[i])
        take = 1 + solveRec(i+1, i, nums);

    int notTake = solveRec(i+1, prev, nums);

    return max(take, notTake);
}

int LIS_Recursion(vector<int>& nums){
    return solveRec(0, -1, nums);
}


/*-------------------------------------------------
2) MEMOIZATION (Top Down DP) — O(n^2)
-------------------------------------------------*/
int solveMemo(int i, int prev, vector<int>& nums, vector<vector<int>>& dp){
    if(i == nums.size())
        return 0;

    if(dp[i][prev+1] != -1)
        return dp[i][prev+1];

    int take = 0;
    if(prev == -1 || nums[prev] < nums[i])
        take = 1 + solveMemo(i+1, i, nums, dp);

    int notTake = solveMemo(i+1, prev, nums, dp);

    return dp[i][prev+1] = max(take, notTake);
}

int LIS_Memoization(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return solveMemo(0, -1, nums, dp);
}


/*-------------------------------------------------
3) TABULATION DP — O(n^2)
-------------------------------------------------*/
int LIS_Tabulation(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n,1);

    int ans = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}


/*-------------------------------------------------
4) BINARY SEARCH (Optimal) — O(n log n)
-------------------------------------------------*/
int LIS_BinarySearch(vector<int>& nums){
    vector<int> tails;

    for(int x : nums){
        auto it = lower_bound(tails.begin(), tails.end(), x);

        if(it == tails.end())
            tails.push_back(x);
        else
            *it = x;
    }

    return tails.size();
}


/*-------------------------------------------------
MAIN DRIVER (for local testing)
-------------------------------------------------*/
int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};

    cout << "Recursion: " << LIS_Recursion(nums) << endl;
    cout << "Memoization: " << LIS_Memoization(nums) << endl;
    cout << "Tabulation: " << LIS_Tabulation(nums) << endl;
    cout << "Binary Search: " << LIS_BinarySearch(nums) << endl;

    return 0;
}