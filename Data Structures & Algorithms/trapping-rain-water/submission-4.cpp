class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2) return 0;

        int ans=0;

        // int l=0, r=n-1;
        // while(l<r){
        //     if(height[l]<height[r]){
        //         lmax = max(lmax, height[l]);
        //         ans+=(lmax-height[l]);
        //         l++;
        //     }
        //     else{
        //         rmax = max(rmax, height[r]);
        //         ans+=(rmax-height[r]);
        //         r--;
        //     }
        // }

        vector<int> lmax(n), rmax(n);
        lmax[0] = height[0];
        rmax[n-1] = height[n-1];

        for(int i=1;i<n;i++) lmax[i] = max(lmax[i-1], height[i]);
        for(int i=n-2;i>=0;i--) rmax[i] = max(rmax[i+1], height[i]);

        for(int i=1;i<n-1;i++) ans += max(0, min(rmax[i+1],lmax[i-1]) - height[i]);

        return ans;
    }
};
