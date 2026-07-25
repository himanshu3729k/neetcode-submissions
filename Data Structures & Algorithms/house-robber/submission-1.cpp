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
        // if(n<=1) return nums[0];
        // dp.assign(n+1, -1);
        // return max(rec(0, nums), rec(1, nums));

        int dp[105] = {0};

        for(int i=n-1;i>=0;i--){
            int ans = nums[i];
            for(int j=i+2;j<n;j++){
                ans = max(ans, dp[j]+nums[i]);
            }
            dp[i] = ans;
        }

        return max(dp[0], dp[1]);
    }
};
