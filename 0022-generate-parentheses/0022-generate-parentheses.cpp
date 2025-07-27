class Solution {
public:
    vector<string> res;
    string temp = "";

    void gen(int o, int c, int n) {
        if(temp.size() == n*2) {
            res.push_back(temp);
            return;
        }

        if(o < n) {
            temp.push_back('(');
            gen(o+1,c,n);
            temp.pop_back();
        }
        if(c < o) {
            temp.push_back(')');
            gen(o,c+1,n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        gen(0,0,n);
        return res;
    }
};