class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if(size==1) {
            return nums[0];
        }

        int start = nums[0];
        int end = nums[size - 1];
        bool sorted = true;

        int left = 0;
        int right = size - 1;
        int pivot = 0;

        
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] > end) {
                    if (nums[mid] > nums[mid + 1]) {
                        sorted = false;
                        pivot = mid; //0
                        break;
                    }
                    left = mid + 1;
                }

                else if (nums[mid] < end) {
                    right = mid - 1;
                }
            }
        
        if( pivot == 0 && !sorted) {
            return nums[pivot+1];   
        }

        else if(pivot == 0 && sorted) {
            return start;
        } 

        else return nums[pivot+1];

        return pivot;
    }
};