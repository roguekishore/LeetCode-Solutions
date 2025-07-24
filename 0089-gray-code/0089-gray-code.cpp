class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int total = 1<<n;
        for(int i = 0 ; i<total ; i++) {
            result.push_back(i ^ (i>>1));
        }
        // result.push_back(0);
        // queue<int> q;
        // q.push(1);
        // bool left = true;
        // while(--total > 0) {
        //     int num = q.front();
        //     q.pop();
        //     result.push_back(num);
        //     if(!left) {
        //         q.push(num<<1);
        //         q.push(num<<1 | 1);
        //     } else {
        //         q.push(num<<1 | 1);
        //         q.push(num<<1);
        //     }
        //     left = !left;
        // }
        return result;
    }
};