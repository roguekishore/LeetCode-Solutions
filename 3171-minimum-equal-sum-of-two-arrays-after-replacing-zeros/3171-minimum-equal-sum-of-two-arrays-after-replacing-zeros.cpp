class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long sum = 0;
        int zeroOne = 0;
        int zeroTwo = 0;

        long sumOne = 0;
        long sumTwo = 0;

        for(int i=0 ; i<nums1.size() ; i++) {
            sumOne+=nums1[i];
            if(nums1[i]==0) {
                zeroOne++;
            }
        } for(int i=0 ; i<nums2.size() ; i++) {
            sumTwo+=nums2[i];
            if(nums2[i]==0) {
                zeroTwo++;
            }
        }
        cout<<sumOne<<" "<<sumTwo;
        cout<<endl<<zeroOne<<" "<<zeroTwo;
        if(zeroOne>0)
            sumOne += (zeroOne);
        if(zeroTwo>0)
            sumTwo += (zeroTwo);
        
        if( sumTwo>sumOne && (zeroOne>0) ) {
            return sumTwo;
        } else if( sumTwo<sumOne && (zeroTwo>0) ){
            return sumOne;
        } else if( sumTwo==sumOne ) {
            return sumTwo;
        } 
        return -1;
    }
};