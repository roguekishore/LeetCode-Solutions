class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        map<int,int> map;
        for(int i=0 ; i<size ; i++) {
            map[nums[i]]++;
        }

        int n = size/3;
        vector<int> majority;

        for(auto it : map) {
            if(it.second > n) {
                majority.push_back(it.first);
            }
        }

        return majority;
    }
};