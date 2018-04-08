//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方
class Solution {
public:
    double Power(double base, int exponent) {
        int n = exponent;
        if(equal(base,0.0))
            return 0.0;
        if(exponent<0)
            n = -exponent;
        double result = 1.0;
        for(int i=0;i<n;i++)
            result *= base;
        if(exponent<0)
            return 1.0/result;
        return result;
         
    }
     
    bool equal(double num1, double num2){
        if((num1-num2>-0.0000001) && (num1-num2<0.0000001))
            return true;
        else
            return false;
    }
};
