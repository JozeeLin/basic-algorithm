//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        //类似冒泡算法
        int length = array.size();
        if(length <=0 )
            return;
        int Left = 0;//指向从左至右最近的一个偶数
        int Right = 1; //指向从左至右最近的一个奇数
        while(Right<length){
            while(Right<length && array[Left]%2==1){
                Left++;
                Right++;
            }
            while(Right<length && array[Right]%2==0){
                Right++;
            }
            int tmp;
            int i = Right-1;
            int j = Right;
            while(Right<length && i>=Left){
                tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
                i--;
                j--;
            }
        }
    }
};
