class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2) return 0;

        int ans=0;
        vector<int> lmax(n), rmax(n);
        // int lval=0, rval=0;
        lmax[0] = height[0];
        rmax[n-1] = height[n-1];

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
        for(int i=1;i<n;i++){
            lmax[i] = max(lmax[i-1], height[i]);
            // lmax[i] = lval;
        }
        for(int i=n-2;i>=0;i--){
            rmax[i] = max(rmax[i+1], height[i]);
            // rmax[i] = rval;
        }

        // for(int i=0;i<n;i++) cout<<lmax[i]<<' ';
        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<rmax[i]<<' ';

        for(int i=1;i<n-1;i++){
            ans += max(0, min(rmax[i+1],lmax[i-1]) - height[i]);
        }

        return ans;
    }
};
