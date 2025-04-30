class Solution {
public:
    bool getNumbers(int n) {
        if ((n>=1 && n<=9) || (n>=100 && n<=999) || (n>=10000 && n<=99999) || (n>=1000000 && n<=9999999) ||             (n>=100000000 && n<=999999999)) {
            return false;
            }

        return true;
    }
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (getNumbers(nums[i]))
                count++;
        }

        return count;
    }
};