/*
LeetCode 1911 - Maximum Alternating Subsequence Sum
Contains 4 Approaches:
1) Recursion (Brute Force)
2) Memoization (Top Down DP)
3) Tabulation (Bottom Up DP)
4) Space Optimized DP (Best Solution)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    /*----------------------------------------------------------
    1) RECURSION (BRUTE FORCE)  --- O(2^N)
    ----------------------------------------------------------*/
    ll solveRec(int idx, bool isEven, vector<int>& nums){
        if(idx >= nums.size()) return 0;

        ll val = nums[idx];
        if(!isEven) val = -val;

        ll take = val + solveRec(idx+1, !isEven, nums);
        ll notTake = solveRec(idx+1, isEven, nums);

        return max(take, notTake);
    }

    long long recursionSolution(vector<int>& nums){
        return solveRec(0, true, nums);
    }


    /*----------------------------------------------------------
    2) MEMOIZATION (TOP DOWN DP) --- O(N)
    ----------------------------------------------------------*/
    vector<vector<ll>> dp;

    ll solveMemo(int idx, bool isEven, vector<int>& nums){
        if(idx >= nums.size()) return 0;

        if(dp[idx][isEven] != -1)
            return dp[idx][isEven];

        ll val = nums[idx];
        if(!isEven) val = -val;

        ll take = val + solveMemo(idx+1, !isEven, nums);
        ll notTake = solveMemo(idx+1, isEven, nums);

        return dp[idx][isEven] = max(take, notTake);
    }

    long long memoizationSolution(vector<int>& nums){
        int n = nums.size();
        dp.assign(n, vector<ll>(2, -1));
        return solveMemo(0, true, nums);
    }


    /*----------------------------------------------------------
    3) TABULATION (BOTTOM UP DP) --- O(N)
    ----------------------------------------------------------*/
    long long tabulationSolution(vector<int>& nums){
        int n = nums.size();

        vector<vector<ll>> dp(n+1, vector<ll>(2, 0));

        for(int i=n-1;i>=0;i--){
            // next position is EVEN (+)
            dp[i][1] = max(
                nums[i] + dp[i+1][0],   // take
                dp[i+1][1]              // skip
            );

            // next position is ODD (-)
            dp[i][0] = max(
                -nums[i] + dp[i+1][1],  // take
                dp[i+1][0]              // skip
            );
        }

        return dp[0][1];
    }


    /*----------------------------------------------------------
    4) SPACE OPTIMIZED DP (BEST) --- O(N) time | O(1) space
    ----------------------------------------------------------*/
    long long spaceOptimizedSolution(vector<int>& nums){

        ll even = 0; // next pick is +
        ll odd = 0;  // next pick is -

        for(int num : nums){
            ll newEven = max(even, odd + num);
            ll newOdd = max(odd, even - num);

            even = newEven;
            odd = newOdd;
        }

        return even;
    }


    /*----------------------------------------------------------
    FINAL LEETCODE FUNCTION (uses best solution)
    ----------------------------------------------------------*/
    long long maxAlternatingSum(vector<int>& nums) {
        return spaceOptimizedSolution(nums);
    }
};


int main(){
    Solution obj;
    vector<int> nums = {4,2,5,3};
    cout << obj.maxAlternatingSum(nums);
}




