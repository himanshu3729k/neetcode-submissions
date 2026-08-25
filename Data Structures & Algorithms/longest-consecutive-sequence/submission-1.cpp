class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> st;
        for(int x:nums) st.insert(x);

        vector<int> start;
        for(int x:st) if(!st.count(x-1)) start.push_back(x);

        int max_len = 1;
        for(int x:start){
            int curr=x, clen=1;
            while(st.count(curr+1)){
                clen++;
                curr++;
            }

            max_len = max(max_len, clen);
        }

        return max_len;
    }
};
