class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ind;

        for(int i=0;i<nums.size();i++){
            int req = target - nums[i];

            if(ind.count(req)) return {ind[req], i};

            else ind[nums[i]] = i;
        }

        return {};
    }
};
