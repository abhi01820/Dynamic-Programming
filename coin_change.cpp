#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

/*---------------------------------------------------
1️⃣ RECURSION (Brute Force)
Time: Exponential
---------------------------------------------------*/
int solveRec(vector<int>& coins, int sum, int i){

    if(sum == 0) return 1;

    if(i >= coins.size() || sum < 0) return 0;

    int take = solveRec(coins, sum - coins[i], i);

    int notTake = solveRec(coins, sum, i + 1);

    return take + notTake;
}

int recursion(vector<int>& coins, int sum){
    return solveRec(coins, sum, 0);
}


/*---------------------------------------------------
2️⃣ MEMOIZATION (Top Down DP)
Time: O(n * sum)
---------------------------------------------------*/
int solveMemo(vector<int>& coins,int sum,int i,vector<vector<int>>& dp){

    if(sum == 0) return 1;

    if(i >= coins.size() || sum < 0) return 0;

    if(dp[i][sum] != -1) return dp[i][sum];

    int take = solveMemo(coins,sum - coins[i],i,dp);

    int notTake = solveMemo(coins,sum,i+1,dp);

    return dp[i][sum] = take + notTake;
}

int memoization(vector<int>& coins,int sum){

    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(sum+1,-1));

    return solveMemo(coins,sum,0,dp);
}


/*---------------------------------------------------
3️⃣ TABULATION (Bottom Up DP)
Time: O(n * sum)
---------------------------------------------------*/
int tabulation(vector<int>& coins,int sum){

    int n = coins.size();

    vector<vector<int>> dp(n+1, vector<int>(sum+1,0));

    for(int i=0;i<=n;i++)
        dp[i][0] = 1;

    for(int i=n-1;i>=0;i--){
        for(int s=1;s<=sum;s++){

            int take = 0;

            if(s >= coins[i])
                take = dp[i][s - coins[i]];

            int notTake = dp[i+1][s];

            dp[i][s] = take + notTake;
        }
    }

    return dp[0][sum];
}


/*---------------------------------------------------
4️⃣ SPACE OPTIMIZED (1D DP)
Best solution
Time: O(n * sum)
Space: O(sum)
---------------------------------------------------*/
int spaceOptimized(vector<int>& coins,int sum){

    vector<int> dp(sum+1,0);

    dp[0] = 1;

    for(int coin : coins){

        for(int s = coin; s <= sum; s++){

            dp[s] += dp[s - coin];

        }
    }

    return dp[sum];
}

};


int main(){

    Solution obj;

    vector<int> coins = {1,2,3};

    int sum = 4;

    cout << "Recursion: " << obj.recursion(coins,sum) << endl;

    cout << "Memoization: " << obj.memoization(coins,sum) << endl;

    cout << "Tabulation: " << obj.tabulation(coins,sum) << endl;

    cout << "Space Optimized: " << obj.spaceOptimized(coins,sum) << endl;

}
