class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            else if (nums[mid] >= nums[left]) {
                if (target <= nums[mid] && target >= nums[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            else {
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
    return -1;
    }

    // int size = nums.size();
    // if(size==1) {
    //     return (nums[0]==target) ? 0 : -1;
    // }

    // bool sorted = true;
    // int start = nums[0];
    // int end = nums[size-1];

    // int left = 0;
    // int right = size-1;
    // int pivot = 0;

    // while(left<=right) {
    //     int mid = left + (right - left) / 2;
    //     if( nums[mid] > end ) {
    //         if(nums[mid] > nums[mid+1]) {
    //             sorted = false;
    //             pivot = mid;
    //             break;
    //         }
    //         left = mid + 1;
    //     }
    //     else if( nums[mid] < end ) {
    //         right = mid-1;
    //     }
    // }

    // cout<<nums[pivot]<<endl;
    // if(sorted && pivot==0) {
    //     left = 0;
    //     right = size - 1;
    // }

    // else {
    //     if(target >= start ) {
    //         left = 0;
    //         right = pivot;
    //     }
    //     else {
    //         left = pivot+1;
    //         right = size - 1;
    //     }

    // }
    // cout<<left<<"->"<<right<<endl;
    // while(left <= right) {
    //     int mid = left + (right - left) / 2;
    //     if( nums[mid] == target ) {
    //         return mid;
    //     }
    //     else if( nums[mid] < target ) {
    //         left = mid+1;
    //     }
    //     else {
    //         right = mid-1;
    //     }
    // }

    // return -1;
};

