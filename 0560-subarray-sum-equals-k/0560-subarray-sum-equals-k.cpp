class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int n = 0;
        int sum = 0;

        for(int right=0 ; right<nums.size() ; right++) {
            sum += nums[right];

            if(map.find(sum-k) != map.end()) {
                n += map[sum-k];
            }

            map[sum]++;
        }
        return n;
    }
};