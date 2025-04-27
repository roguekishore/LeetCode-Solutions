class Solution {
    public int[] searchRange(int[] nums, int target) {
        if(nums.length == 1 && nums[0] == target) return new int[]{0,0} ;
        if(nums.length == 0 || nums.length == 1) return new int[]{-1,-1} ;
        int left = 0; int right = nums.length-1;

        while(left < right){
            if(nums[left] == target && nums[right] == target){
                break;
            }

            else if(nums[left] == target && nums[right] != target){
                right--;
            }

            else if(nums[left] != target && nums[right] == target){
                left++;
            }

            else{
                left++;
                right--;
            }
        }

        if(nums[left]==target && nums[right]==target ){
            int[] arr = new int[2];
            arr[0] = left;
            arr[1] = right;
            return arr;
        }

        return new int[]{-1,-1};
    }
}