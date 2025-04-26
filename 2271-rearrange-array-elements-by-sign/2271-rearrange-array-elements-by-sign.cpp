class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size = nums.size();
        int pos = 0;
        int neg = 1;
        vector<int> result(size);

        for(int i=0 ; i<size ; i++) {
            if( nums[i] >= 0 ) {
                result[pos] = nums[i];
                pos+=2;
            }
            else {
                result[neg] = nums[i];
                neg+=2;
            }
        }

        return result;
    }
};