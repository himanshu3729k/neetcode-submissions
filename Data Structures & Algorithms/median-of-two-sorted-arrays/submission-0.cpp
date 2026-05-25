class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        int total=nums1.size()+nums2.size();
        int med1=0, med2=0;

        int i=0, j=0;
        for(int x=0; x<(n+m)/2+1; x++){
            med2=med1;

            if(i<n && j<m){
                if(nums1[i]<=nums2[j]){
                    med1=nums1[i];
                    i++;
                }
                else{
                    med1=nums2[j];
                    j++;
                }
            }

            else if(i<n){
                med1=nums1[i];
                i++;
            }
            else if(j<m){
                med1=nums2[j];
                j++;
            }
        }
        
        if(total%2==0){
            return (double)(med1+med2)/2;
        }
        return (double)med1;
    }
};
