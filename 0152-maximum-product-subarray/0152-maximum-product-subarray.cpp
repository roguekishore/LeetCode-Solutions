class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();

        if(size == 1) {
            return nums[0];
        }

        int maxProduct = *max_element(nums.begin(), nums.end());
        int cMax = 1, cMin = 1;

        for(int i=0 ; i<size ; i++) {
            int temp = cMax * nums[i];
            cMax = max({cMin*nums[i], temp, nums[i]});
            cMin = min({cMin*nums[i], temp, nums[i]});

            maxProduct = max(maxProduct, cMax);
        }

        return maxProduct;
    }
};