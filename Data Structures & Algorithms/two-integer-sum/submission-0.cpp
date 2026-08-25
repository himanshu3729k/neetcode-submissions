class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> ind;

        for(int i=0;i<nums.size();i++){
            ind[nums[i]].push_back(i);
        }

        for(int i=0;i<nums.size();i++){
            int req = target - nums[i];
            if(ind.count(req)){
                auto& v = ind[req];
                for(int j=0; j<v.size(); j++){
                    if(v[j] != i) return {i,v[j]};
                }
            }
        }

        return {-1,-1};
    }
};
