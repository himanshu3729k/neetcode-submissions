class Solution {
public:
    // vector<int> dp;
    int n;
    // int rec(int i, vector<int>& nums){
    //     if(i>=n) return 0;
    //     if(dp[i] != -1) return dp[i];

    //     int ans = nums[i];
    //     for(int j=i+2;j<n;j++){
    //         ans = max(ans, rec(j, nums) + nums[i]);
    //     }

    //     return dp[i] = ans;
    // }

    int rob(vector<int>& nums) {
        n = nums.size();
        if(n<=1) return nums[0];
        // dp.assign(n+1, -1);
        // return max(rec(0, nums), rec(1, nums));

        vector<int> dp(n+1,0);
        dp[n-1] = nums[n-1];

        for(int i=n-2;i>=0;i--){
            dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
        }

        // return max(dp[0], dp[1]);
        return dp[0];
    }
};
