class Solution {
private:
    int kthsmallest(vector<int>& nums1, vector<int>& nums2, int k){
        int n=nums1.size(), m=nums2.size();
        int id1=0, id2=0;

        while(1){
            if(id1==n) return nums2[id2+k-1];
            if(id2==m) return nums1[id1+k-1];
            if(k==1) return min(nums1[id1], nums2[id2]);

            int rmv=k/2;
            int pt1 = min(id1+rmv,n)-1;
            int pt2 = min(id2+rmv,m)-1;

            if(nums1[pt1] <= nums2[pt2]){
                k-=(pt1-id1+1);
                id1=pt1+1;
            }
            else{
                k-=(pt2-id2+1);
                id2=pt2+1;
            }
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
    
        if((n+m)&1) return 1.0*kthsmallest(nums1, nums2, ((n+m)/2)+1);

        else{
            int v1 = kthsmallest(nums1, nums2, (n+m)/2);
            int v2 = kthsmallest(nums1, nums2, ((n+m)/2)+1);
            return (v1+v2)/2.0;
        }
    }
};
