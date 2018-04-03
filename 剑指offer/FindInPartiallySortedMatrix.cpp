/*
 * 面试题3：二维数组中的查找
 * 在一个二维数组中，每行都是升序排列，每一列也都是升序排列。输入这样的一个二位数组，和一个整数，判断数组中是否存在该整数
 * 
 * 思路：
 *
 * 每一行的最末尾的数是这一行的最大数，同时也是该数所在列的最小数，
 * 如果输入的整数大于这一行的最大数，就可以直接跳过该行的遍历。这样只需
 * 要判断一次就可以减少很多次没有意义的比较和遍历。
 *
 * 如果输入的整数小于这一行的最大数，也就是小于所在列的最小数，那么可以跳过
 * 该列的遍历。
 *
 * 如果输入的整数等于这一行的最大数，直接返回true，表示该二维数组中包含有
 * 输入的整数。
 */
#include <iostream>

using namespace std;

bool Find(int *matrix, int rows, int columns, int number){
    bool found = false;
    int RowStart = 0;
    int ColumnEnd = columns-1;
    
    //防御性编程，需要检查参数
    if(matrix==NULL || rows<=0 || columns<=0)
        return false;

    while(RowStart < rows && ColumnEnd >= 0){
        if(number > matrix[RowStart*columns+ColumnEnd])
            RowStart++;
        else if(number < matrix[RowStart*columns+ColumnEnd])
            ColumnEnd--;
        else
            return true;
    }
    return found;
}

int main()
{
    /*
     * 测试用例
     * 1.查找的数字是数组中的最大值和最小值
     * 2.查找数字介于最大最小值之间
     * 3.查找数字不存在数组中，大于数组最大值、小于数组的最小值
     * 4.查找数字不存在数组中，介于最大值最小值之间
     * 5.空指针，rows、columns不是整数
     */
    int arr[16] = {1,2,3,5,6,9,12,15,23,27,35,46,55,66,77,88};
    int rows = 4;
    int columns=4;
    cout<<Find(arr, rows,columns,88)<<endl;
    cout<<Find(arr, rows,columns,1)<<endl;
    cout<<Find(arr, rows,columns,23)<<endl;
    cout<<Find(arr, rows, columns,99)<<endl;
    cout<<Find(arr,rows,columns,-1)<<endl;
    cout<<Find(arr,rows,columns,31)<<endl;
    cout<<Find(NULL,rows,columns,35)<<endl;
    cout<<Find(arr,0,columns,35)<<endl;
}
