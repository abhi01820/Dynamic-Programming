

#include <bits/stdc++.h>
using namespace std;

class RecursionSol{
    public:
        int solve(vector<int>& jobs,int idx,int d,int n){


            
            if(d==1){
                int maxi=jobs[idx];
                for(int i=idx;i< n;i++){
                    maxi=max(maxi,jobs[i]);
                }
                return maxi;
            }
            int maxi=jobs[idx];
            int ans=INT_MAX;
            for(int i=idx;i<=n-d;i++){
                maxi=max(maxi,jobs[i]);
                int res=maxi + solve(jobs,i+1,d-1,n);
                ans=min(ans,res);
            }
            return ans;
        }
        int minDifficulty(vector<int>& jobs,int d){
            int n=jobs.size();
            if(n < d) return -1;
            return solve(jobs,0,d,n);
        }
};

// Memoization 
class MemoizationSol{
    public:
        int dp[301][11];
        int solve(vector<int>& jobs,int idx,int d,int n){
            if(d==1){
                int maxi=jobs[idx];
                for(int i=idx;i< n;i++){
                    maxi=max(maxi,jobs[i]);
                }
                return maxi;
            }
            if(dp[idx][d]!=-1) return dp[idx][d];
            int maxi=jobs[idx];
            int ans=INT_MAX;
            for(int i=idx;i<=n-d;i++){
                maxi=max(maxi,jobs[i]);
                int res=maxi + solve(jobs,i+1,d-1,n);
                ans=min(ans,res);
            }
            return dp[idx][d]= ans;
        }
        int minDifficulty(vector<int>& jobs,int d){
            int n=jobs.size();
            if(n < d) return -1;
            memset(dp,-1,sizeof(dp));
            return solve(jobs,0,d,n);
        }
};




int main() {
    vector<int> jobs={6,5,4,3,2,1};
    int d=2;
    RecursionSol r;
    MemoizationSol m;
    cout<<"Recursion : " << r.minDifficulty(jobs,d) << endl;
    cout<< "Memoization : " << m.minDifficulty(jobs,d) << endl;
    return 0;
}
