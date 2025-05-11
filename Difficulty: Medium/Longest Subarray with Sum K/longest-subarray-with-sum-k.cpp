//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int maxLen = 0;
        long long sum = 0;
        unordered_map<long long, int> map;
        
        for(int right = 0 ; right<arr.size() ; right++) {
            sum += arr[right];
            
            // the sum of all elements till that index is equal to k
            if(sum==k) {
                maxLen = max(maxLen, right+1);
            }
            
            // check the sum of elements before
            if(map.find(sum-k) != map.end()) {
                int len = right - map[sum-k];
                maxLen = max(maxLen, len);
            }
            
            //check if the sum is not there
            if(map.find(sum) == map.end()) {
                map[sum] = right;
            }
        }
        
        return maxLen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends