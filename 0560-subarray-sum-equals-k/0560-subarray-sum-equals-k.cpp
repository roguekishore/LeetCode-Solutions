class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        int sum = 0;

        for(int n : nums) {
            sum += n;

            if(map.find(sum - k) != map.end()) {
                count += map[sum - k];
            }
            map[sum]++;
        }

        return count;
    }
};