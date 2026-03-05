#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // --------------------------------
    // Helper Function
    // --------------------------------
    bool hasDuplicates(string& s1,string& s2){
        vector<int> arr(26,0);

        for(char &ch : s1){
            if(arr[ch-'a'] > 0) return true;
            arr[ch-'a']++;
        }

        for(char &ch : s2){
            if(arr[ch-'a'] > 0) return true;
            arr[ch-'a']++;
        }

        return false;
    }


    // =====================================================
    // 1️⃣ RECURSION (Brute Force)
    // Time : O(2^n)
    // =====================================================
    int solveRec(int i,string temp,int n,vector<string>& arr){

        if(i==n) return temp.size();

        int take=0;
        int notTake=0;

        if(!hasDuplicates(arr[i],temp)){
            take = solveRec(i+1,temp+arr[i],n,arr);
        }

        notTake = solveRec(i+1,temp,n,arr);

        return max(take,notTake);
    }


    int recursionApproach(vector<string>& arr){
        return solveRec(0,"",arr.size(),arr);
    }


    // =====================================================
    // 2️⃣ MEMOIZATION (Top Down DP)
    // =====================================================
    unordered_map<string,int> dp;

    int solveMemo(int i,string temp,int n,vector<string>& arr){

        string key = to_string(i) + temp;

        if(dp.count(key)) return dp[key];

        if(i==n) return temp.size();

        int take=0;
        int notTake=0;

        if(!hasDuplicates(arr[i],temp)){
            take = solveMemo(i+1,temp+arr[i],n,arr);
        }

        notTake = solveMemo(i+1,temp,n,arr);

        return dp[key] = max(take,notTake);
    }


    int memoizationApproach(vector<string>& arr){
        dp.clear();
        return solveMemo(0,"",arr.size(),arr);
    }


    // =====================================================
    // 3️⃣ TABULATION (DP with masks)
    // =====================================================
    int tabulationApproach(vector<string>& arr){

        vector<int> dp = {0};

        int ans = 0;

        for(string &s : arr){

            int mask = 0;
            bool duplicate = false;

            for(char c : s){
                int bit = c-'a';

                if(mask & (1<<bit)){
                    duplicate = true;
                    break;
                }

                mask |= (1<<bit);
            }

            if(duplicate) continue;

            int size = dp.size();

            for(int i=0;i<size;i++){

                if((dp[i] & mask) == 0){

                    int newMask = dp[i] | mask;
                    dp.push_back(newMask);

                    ans = max(ans, __builtin_popcount(newMask));
                }
            }
        }

        return ans;
    }


    // =====================================================
    // 4️⃣ SPACE OPTIMIZED (Bitmask Backtracking)
    // =====================================================
    int solveMask(int i,int mask,vector<int>& masks){

        if(i==masks.size())
            return __builtin_popcount(mask);

        int take = 0;

        if((mask & masks[i]) == 0){
            take = solveMask(i+1, mask | masks[i], masks);
        }

        int notTake = solveMask(i+1, mask, masks);

        return max(take,notTake);
    }


    int bitmaskApproach(vector<string>& arr){

        vector<int> masks;

        for(string &s : arr){

            int mask = 0;
            bool duplicate = false;

            for(char c : s){

                int bit = c-'a';

                if(mask & (1<<bit)){
                    duplicate = true;
                    break;
                }

                mask |= (1<<bit);
            }

            if(!duplicate)
                masks.push_back(mask);
        }

        return solveMask(0,0,masks);
    }

};
