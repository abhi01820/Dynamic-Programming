#include <bits/stdc++.h>
using namespace std;

class Solution {
public:









    /*========================================================
        1) PURE RECURSION (Exponential)
        Time  : O(2^n)
        Space : O(n) recursion stack
    ========================================================*/
    
    int solveRec(vector<vector<int>>& arr, int prev, int idx) {
        if (idx == arr.size())
            return 0;

        int take = 0;
        if (prev == -1 || arr[idx][0] > arr[prev][1]) {
            take = 1 + solveRec(arr, idx, idx + 1);
        }

        int notTake = solveRec(arr, prev, idx + 1);

        return max(take, notTake);
    }

    int approach1(vector<vector<int>> pairs) {
        sort(pairs.begin(), pairs.end());
        return solveRec(pairs, -1, 0);
    }

    /*========================================================
        2) MEMOIZATION (Top-Down DP)
        Time  : O(n^2)
        Space : O(n^2)
    ========================================================*/

    int solveMemo(vector<vector<int>>& arr, int prev, int idx,
                  vector<vector<int>>& dp) {

        if (idx == arr.size())
            return 0;

        if (dp[prev + 1][idx] != -1)
            return dp[prev + 1][idx];

        int take = 0;
        if (prev == -1 || arr[idx][0] > arr[prev][1]) {
            take = 1 + solveMemo(arr, idx, idx + 1, dp);
        }

        int notTake = solveMemo(arr, prev, idx + 1, dp);

        return dp[prev + 1][idx] = max(take, notTake);
    }

    int approach2(vector<vector<int>> pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());

        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        return solveMemo(pairs, -1, 0, dp);
    }

    /*========================================================
        3) TABULATION (Bottom-Up DP)
        Time  : O(n^2)
        Space : O(n)
    ========================================================*/

    int approach3(vector<vector<int>> pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());

        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }

    /*========================================================
        4) GREEDY (Most Optimal)
        Time  : O(n log n)
        Space : O(1)
    ========================================================*/

    int approach4(vector<vector<int>> pairs) {
        sort(pairs.begin(), pairs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int count = 0;
        int lastEnd = INT_MIN;

        for (auto& p : pairs) {
            if (p[0] > lastEnd) {
                count++;
                lastEnd = p[1];
            }
        }

        return count;
    }
};





/*========================================================
                    DRIVER CODE
========================================================*/

int main() {
    Solution sol;

    vector<vector<int>> pairs = {{1,2}, {21,31}, {3,4}};

    cout << "Approach 1 (Recursion): "
         << sol.approach1(pairs) << endl;

    cout << "Approach 2 (Memoization): "
         << sol.approach2(pairs) << endl;

    cout << "Approach 3 (Tabulation): "
         << sol.approach3(pairs) << endl;

    cout << "Approach 4 (Greedy Optimal): "
         << sol.approach4(pairs) << endl;

    return 0;
}
