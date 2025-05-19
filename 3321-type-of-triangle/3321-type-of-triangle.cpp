class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        if( a==b && b==c ) {
            return "equilateral";
        } else if( c>=a+b) {
            return "none";
        } else if( a!=b && b!=c && c!=a) {
            return "scalene";
        } else {
            return "isosceles";
        }

        return "none";
    }
};