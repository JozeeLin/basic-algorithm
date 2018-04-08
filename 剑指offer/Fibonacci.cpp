//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
//n<=39
class Solution {
public:
    int Fibonacci(int n) {
        int n_2 = 1;
        int n_1 = 1;
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 1;
        int result = 0;
        for(int i=3;i<=n;i++)
        {
            result = n_1+n_2;
            n_2 = n_1;
            n_1 = result;
        }
        return result;
    }
};
