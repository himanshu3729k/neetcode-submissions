class Solution {
public:
    vector<int> dp;
    int rec(int i, vector<int>& cost){
        if(i>=cost.size()) return 0;

        if(dp[i]!=-1) return dp[i];

        int ans = INT_MAX;
        ans = min(ans, rec(i+1, cost) + cost[i]);
        ans = min(ans, rec(i+2, cost) + cost[i]);

        return dp[i] = ans;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        dp.assign(105, -1);
        return min(rec(0,cost), rec(1,cost));
    }
};
