class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        if(size == 1) {
            return nums[0] == k;
        }

        int count = 0;
        int  prefix[size];
        prefix[0] = nums[0];

        for(int i=1 ; i<size ; i++) {
            prefix[i] = nums[i] + prefix[i-1];
        }

        map<int, int> map;

        for(int i=0 ; i<size ; i++) {
            if(prefix[i] == k)
                count++;

            if(map.find(prefix[i] - k) != map.end()) {
                count += map[prefix[i] - k];
            }
            map[prefix[i]]++;
        }

        for(auto it:map) {
            cout<<it.first<<"->"<<it.second<<endl;
        }


        return count;
    }
};