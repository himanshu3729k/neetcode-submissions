class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int rec(int i, int last, vector<int>& nums){
        if(i>=n) return 0;

        if(dp[i][last+1] != -1) return dp[i][last+1];

        int ans = rec(i+1, last, nums);
        if(last==-1 || (last>=0 && nums[i]>nums[last]))
            ans = max(ans, 1+rec(i+1, i, nums));

        return dp[i][last+1] = ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        dp.assign(n+1, vector<int>(n+2, -1));

        return rec(0,-1,nums);
    }
};
