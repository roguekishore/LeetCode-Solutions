class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right, vector<int>& temp) {
        int low = left;
        int high = mid+1;
        int k = 0;

        while(low<=mid && high<=right) {
            if(nums[low]<=nums[high]) {
                temp[k++] = nums[low++];
            } else {
                temp[k++] = nums[high++];
            }
        }

        while(low<=mid)
            temp[k++] = nums[low++];

        while(high<=right)
            temp[k++] = nums[high++];

        for(int i=left ; i<=right ; i++) {
            nums[i] = temp[i-left];
        }
    }
    void mergeSort(vector<int>& nums, int left, int right, vector<int>& temp) {
        if(left >= right) {
            return;
        }
        int mid = (left+right)/2;
        mergeSort(nums, left, mid, temp);
        mergeSort(nums, mid+1, right, temp);
        merge(nums, left, mid, right, temp);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size()-1, temp);
        return nums;
    }
};