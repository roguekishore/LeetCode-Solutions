class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> arr;
        sort(nums.begin(), nums.end());
        int size = nums.size();

        for(int i=0 ; i<size ; i++) {
            if( i!=0 && nums[i]==nums[i-1]) {
                continue;
            }

            int left = i+1;
            int right = size-1;

            while(left<right) {
                int sum = nums[i] + nums[left] + nums[right];

                if( sum<0 ) {
                    left++;
                } else if( sum>0 ) {
                    right--;
                } else {
                    arr.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }

            }
        }

        return arr;
    }

    vector<vector<int>> ThreeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> arr;
        set<vector<int>> s;
        map<int, int> map;
        sort(nums.begin(), nums.end());
        for(int i=0 ; i<size ; i++) {
            map[nums[i]] = i;
        }

        for(int i=0 ; i<size-2 ; i++) {
            int left = i+1;
            
            while(left<size) {
                int temp = nums[i] + nums[left];
                if( (map.find(-temp)!=map.end()) && (map[-temp] != left) && (map[-temp] != i)) {
                    vector<int> dummy = {nums[i], nums[left], -temp};
                    sort(dummy.begin(), dummy.end());
                    s.insert(dummy);
                }
                left++;
            }
        }

        for (auto triplets : s) {
            arr.push_back(triplets);
        }

        return arr;
    }
};