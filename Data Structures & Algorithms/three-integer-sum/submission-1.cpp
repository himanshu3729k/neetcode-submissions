class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            if(nums[i]>0) break;
            if(i && nums[i]==nums[i-1]) continue;

            int l=i+1, r=n-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]>0) r--;

                else if(nums[i]+nums[l]+nums[r]<0) l++;

                else{
                    ans.push_back({nums[i],nums[l++],nums[r--]});
                    while(nums[l]==nums[l-1] && l<r) l++;
                }
            }
        }

        return ans;
    }
};
