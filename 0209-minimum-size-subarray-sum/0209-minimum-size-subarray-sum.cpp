class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int prefix[size+1];

        prefix[0] = 0;
        prefix[1] = nums[0];

        for(int i=2 ; i<=size ; i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }

        for(int i=0 ; i<=size ; i++) {
            cout<<prefix[i]<<" ";
        }

        int minWindow = 0;
        int left = 1;
        int right = 1;
        int tempSum = 0;
        while( left<=size ) {
            //cout<<"For index "<<left<<endl;
            while( right<=size ) {
                tempSum = (prefix[right] - prefix[left-1]);
                //cout<<left<<"->"<<right<<" = "<<tempSum<<endl;
                if(tempSum >= target) {
                    if( minWindow == 0) {
                        minWindow = right - left + 1;
                        break;
                    }
                    minWindow = min(minWindow, (right-left+1));
                    break;
                }
                right++;
            }
            left++;
        }

        return minWindow;
    }
};