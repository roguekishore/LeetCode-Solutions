//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int miss = 0;
        int twice = 0;
        vector<int> map(arr.size()+1,0);
        
        for(int i=0 ; i<arr.size() ; i++) {
            map[arr[i]]++;
            if(map[arr[i]] > 1) {
                twice = arr[i];
            }
        }
        
        for(int i=1 ; i<map.size() ; i++) {
            if(map[i] == 0) {
                miss = i;
                break;
            }
        }
        
        return {twice, miss};
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends