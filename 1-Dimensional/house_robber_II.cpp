#include <bits/stdc++.h>
using namespace std;

/*========================================================
1) BRUTE FORCE (RECURSION)  — O(2^N)
========================================================*/
class Solution_Brute {
public:

    int solve(int idx, vector<int>& nums){
        if(idx == 0) return nums[0];
        if(idx < 0) return 0;

        int take = nums[idx] + solve(idx-2, nums);
        int notTake = solve(idx-1, nums);

        return max(take, notTake);
    }

    int helper(vector<int>& arr){
        return solve(arr.size()-1, arr);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> temp1, temp2;

        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);     // exclude first
            if(i!=n-1) temp2.push_back(nums[i]);   // exclude last
        }

        return max(helper(temp1), helper(temp2));
    }
};



/*========================================================
2) MEMOIZATION (TOP-DOWN DP) — O(N)
========================================================*/
class Solution_Memo {
public:

    int solve(int idx, vector<int>& nums, vector<int>& dp){
        if(idx == 0) return nums[0];
        if(idx < 0) return 0;

        if(dp[idx] != -1) return dp[idx];

        int take = nums[idx] + solve(idx-2, nums, dp);
        int notTake = solve(idx-1, nums, dp);

        return dp[idx] = max(take, notTake);
    }

    int helper(vector<int>& arr){
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(n-1, arr, dp);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> temp1, temp2;

        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

        return max(helper(temp1), helper(temp2));
    }
};



/*========================================================
3) TABULATION (BOTTOM-UP DP) — O(N) time, O(N) space
========================================================*/
class Solution_Tabulation {
public:

    int helper(vector<int>& arr){
        int n = arr.size();
        vector<int> dp(n,0);

        dp[0] = arr[0];

        for(int i=1;i<n;i++){
            int take = arr[i];
            if(i>1) take += dp[i-2];

            int notTake = dp[i-1];

            dp[i] = max(take, notTake);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> temp1, temp2;

        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

        return max(helper(temp1), helper(temp2));
    }
};



/*========================================================
4) SPACE OPTIMIZED (MOST OPTIMAL) — O(N) time, O(1) space
========================================================*/
class Solution_Optimal {
public:

    int helper(vector<int>& arr){
        int n = arr.size();

        int prev = arr[0];
        int prev2 = 0;

        for(int i=1;i<n;i++){
            int take = arr[i] + prev2;
            int notTake = prev;

            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> temp1, temp2;

        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

        return max(helper(temp1), helper(temp2));
    }
};