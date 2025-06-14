class Solution {
public:
    int minMaxDifference(int num) {
        string max = to_string(num);
        string min = to_string(num);
        char map = '0';
        for(int i=0 ; i<max.size() ; i++) {
            if(max[i] != '9') {
                map = max[i];
                break;
            }
        }
        if(map != 0) 
            replace(max.begin(), max.end(), map, '9');
        
        map = 9;
        for(int i=0 ; i<min.size() ; i++) {
            if(min[i] != '0') {
                map = min[i];
                break;
            }
        }
        if(map != 9) 
            replace(min.begin(), min.end(), map, '0');

        int maxi = stoi(max);
        int mini = stoi(min);
        
        return maxi-mini;
    }
};