class Solution {
public:

    int sumNumbers(int n) {
        long sum = 0;
        while(n>0) {
            sum = sum+ (n%10);
            n/=10;
        }

        return (int)sum;
    }
    int addDigits(int num) {
        int n = num;
        int sum = sumNumbers(num);
        if( sum<=9 ) {
            return sum;
        }
        else {
            while( sum>9 ) {
                sum = sumNumbers(sum);
            }
            return sum;
        }
    }
};